/* 	*******************************
   	Author: Okeke Nnadozie
   	File Name: feedInputQueue.c
   	******************************************************************************************************
   	Function: Contains the implementation for feedInputQueues
   	****************************************************************************************************** */
	#include <string.h>
	#include <stdio.h>
	//#define DISPLAYQUEUES
	#include "feedInputQueue.h"
	#include <unistd.h>
	//#define DEBUGEXTERN
	//#define DEBUGMULTIPLEX
	//#define DEBUGDEMUL

   	int L2MAXLOAD; //value is assigned in main function, and needed here.

/*	****************************************************************
	feedInputQueues reads in all valid packets from the example file
	and queues all of them in their respective input queues.
	**************************************************************** */
	void feedInputQueues()
	{
	
	/*	**********************************************************
		Declaration of all variables used by this function
		********************************************************** */
		enum inputQueues {inptQA, inptQB, inptQC, inptQD, inptQE, mainQ};
		
   		char layer2[32];
   		char l2PayLoad[L2MAXLOAD];
   		char filename[50];
   		char waste;
		
		int i, inptQSize, mainQSize;
		int l2SrcAdrs;
		//int numOfChecksOf[5];
		FILE *fptr;
	//end variable declaraton


	/*	***********************************
		create all queues of router ecs501u
		*********************************** */
		for(i = 0; i < 11; i++)
		{
			create(i);
		}
	//end create


	/*	*****************************************************************************
		Set the size of the input Queues and main queue, and get the csv filename.
		***************************************************************************** */
		puts("Enter size of input queues"); //make robust so only ints can be entered
		scanf("%d", &inptQSize);
		waste = getchar();

		puts("Enter size of main queue"); //make robust so only ints can be entered
		scanf("%d", &mainQSize);
		waste = getchar();

		puts("Enter the name of file which contains packet information [current filename: file.csv]");
		scanf("%s", filename);
		waste = getchar();
	//end user input collection


	/*	***************************************************
		Open .csv file and create room for error in opening
		*************************************************** */
		fptr = fopen(filename, "r");
		if(fptr == NULL)
		{	puts("Error: Could not open file"); }
		else
		{
	//end open .csv file


		/*	*********************************************************************
			Get packets from .csv file and queue them in appropriate input queues.
			Also check source address of packets for their validity.
			********************************************************************* */
			puts("\n\n--------------------------------------");
			puts("INPUTING PACKETS AND MULTIPLEXING THEM");
			puts("--------------------------------------\n");
			while(feof(fptr) == 0)
			{   		
		   		csvPaktReader(layer2, fptr);
		   		l2PayLoadExtractor(layer2, l2PayLoad);

		   		switch (layer2[0])
		   		{
		   		case 'A':
			   		if(queueSize(inptQA) < inptQSize)
			   		{
			   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQA);
			   			progressReport(inptQA);
			   		}
			   		break;
			   	case 'B':
			   		if(queueSize(inptQB) < inptQSize)
			   		{
			   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQB);
			   			progressReport(inptQB);
			   		}
			   		break;
			   	case 'C':
			   		if(queueSize(inptQC) < inptQSize)
			   		{
			   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQC);
			   			progressReport(inptQC);
			   		}
			   		break;
			   	case 'D':
			   		if(queueSize(inptQD) < inptQSize)
			   		{
			   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQD);
			   			progressReport(inptQD);
			   		}
			   		break;
			   	case 'E':
			   		if(queueSize(inptQE) < inptQSize)
			   		{
			   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQE);
			   			progressReport(inptQE);
			   		}
			   		break;
			   	default:
			   		puts("Error: Source address is invalid");
			   		break;
			   	}//end switch

				multiplexer(inptQSize, mainQSize);

				#ifdef DEBUGDEMUL
				puts("I got here in feedInputQueues");
				#endif

				deMultiplexer(mainQSize);

			}//end while loop


			/*	********************************************************************************************
				Depending on the buffer size of the inputQueues i.e inptQsize - the demultiplexer is to wait 
				until this buffer size is reached - not all inputQueues may have been emptied at this stage in
				the program if they did not recieve enough packets to reach the buffer size specified, or they have
				not been polled for the specified number of times. Therefore, the code below multiplexes until 
				all input queues have been emptied.
				********************************************************************************************** */

				while ( queueSize(inptQA) > 0 || queueSize(inptQB) > 0 || queueSize(inptQC) > 0 || 
						queueSize(inptQD) > 0 || queueSize(inptQE) > 0)
				{
					if (queueSize(mainQ) == mainQSize)
					{
						break;
					}

					else
						if ( queueSize(inptQA) == 0 && queueSize(inptQB) == 0 && queueSize(inptQC) == 0 && 
							 queueSize(inptQD) == 0 && queueSize(inptQE) == 0)
						{
							break;
						}
					else

					#ifdef DEBUGMULTIPLEX
					display(0);
					display(1);
					display(2);
					display(3);
					display(4);
					#endif

					{ multiplexer(inptQSize, mainQSize);
					  deMultiplexer(mainQSize);	
					}
				}


			/*	****************************************************
				Make sure that main queue is completely dequeued
				**************************************************** */
				while (queueSize(mainQ) > 0)
				{
					deMultiplexer(mainQSize);
				}

		}//end ifelse statement
		// finish getting packets.

		fclose(fptr);	//close file

		#ifdef DISPLAYQUEUES
			display(inptQA);
			display(inptQB);
		#endif

	}
//end feedInputQueues



/*	************************************
	progress report
	************************************ */
	void progressReport(int queue)
	{
		printf("\n\nPacket passing through input queue %d:\n", queue );
		display(queue);
		sleep(0.4); //4
  	
  		puts("______________________");
		puts("Packets in main queue:");
		puts("-----------------------");
		display(5);
		puts("-----------------------");
		sleep(0.4); //4
	}



/*	**************************************************************************
	csvPaktReaderis used for reading in layer 2 packets from the example file.
	************************************************************************** */
	void csvPaktReader(char layer2[], FILE *fptr)
	{
		char inputLine[42];
		fgets(inputLine, 42, fptr);
						
		int k = 0;
		int j = 0;
		int comma = 0;
		int space = 0;
		int front = 0;
		int back = 0;

		for (j = 0; j < strlen(inputLine); j++)
		{
			if (inputLine[j] == ',')
			{
				comma = comma + 1;
				if(comma == 3)
				{
					if(inputLine[j - 2] != ' ')
					{
						layer2[2] = inputLine[j - 2];
					}
					else
					{
						layer2[2] = ' ';
					}

					layer2[3] = inputLine[j-1];
					k = 4;
				}
				if(comma == 4)
				{
					if(inputLine[j - 2] != ' ')
					{
						layer2[4] = inputLine[j - 2];
					}
					else
					{
						layer2[4] = ' ';
					}

					layer2[5] = inputLine[j-1];
					k = 6;
				}
				continue;
			}
			else 
				if (inputLine[j] == ' ')
				{

				/*	space = space + 1;
		
					if (space == 3)
					{
						front = k + 1;
					}
					if (space == 4)
					{
						back = k;
					}*/
					continue;	//PUTTING A CONTINUE IS CRITICAL

					}
			else
			{
				layer2[k] = inputLine[j];
				k++;
			}

			//k++;
		}

		layer2[k] = '\0';  //DOING THIS IS CRITICAL

		#ifdef DEBUG
			puts(inputLine);
			puts(layer2);
			printf("%d %d\n", front, back);
		#endif

		return;
	}		
//end layer2 packet reader.



/*	*************************************
	L2PAYLOAD extractor extracts layer 2's
	payload from the read in packets.
	************************************* */
	void l2PayLoadExtractor(char layer2[], char l2PayLoad[])
	{
		#ifdef DEBUG
			puts(layer2);
		#endif

		int k;
		for (k = 0; k < L2MAXLOAD; k++)
		{
			l2PayLoad[k] = layer2[k + 2];
		}

		#ifdef DEBUGEXTERN
			//puts(l2PayLoad);
			printf("%d\n", L2MAXLOAD );
		#endif

		return;
	}
//end layer2payload extractor
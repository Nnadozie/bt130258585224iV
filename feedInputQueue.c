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

   	int L2MAXLOAD;

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
		
		int l3DstAdrsLocation[2];
   		char layer2[32];
   		char l2PayLoad[L2MAXLOAD];
   		char filename[50];
   		char waste;
		
		int i, inptQSize, mainQSize;
		int l2SrcAdrs;
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

		puts("Enter the name of file which contains packet information");
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
		   		csvPaktReader(layer2, l3DstAdrsLocation, fptr);
		   		l2PayLoadExtractor(layer2, l2PayLoad);

		   		switch (layer2[0])
		   		{
		   		case 'A':
			   		if(queueSize(inptQA) < inptQSize)
			   		{
			   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQA);
			   			display(inptQA);
			   			sleep(2);
			   		}
			   		break;
			   	case 'B':
			   		if(queueSize(inptQB) < inptQSize)
			   		{
			   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQB);
			   			display(inptQB);
			   		}
			   		break;
			   	case 'C':
			   		if(queueSize(inptQC) < inptQSize)
			   		{
			   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQC);
			   			display(inptQC);
			   		}
			   		break;
			   	case 'D':
			   		if(queueSize(inptQD) < inptQSize)
			   		{
			   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQD);
			   			display(inptQD);
			   		}
			   		break;
			   	case 'E':
			   		if(queueSize(inptQE) < inptQSize)
			   		{
			   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQE);
			   			display(inptQE);
			   		}
			   		break;
			   	default:
			   		puts("Error: Source address is invalid");
			   		break;
			   	}//end switch

			multiplexer(mainQSize);
			   	/*puts("__________");
			   	puts("MAIN QUEUE");
			   	puts("----------");
			   	display(mainQ);
			   	puts("_______________________");*/
			}//end while loop

		}//end ifelse statement
		// finish getting packets.

		fclose(fptr);	//close file

		#ifdef DISPLAYQUEUES
			display(inptQA);
			display(inptQB);
		#endif

	}
//end feedInputQueues



/*	**************************************************************************
	csvPaktReaderis used for reading in layer 2 packets from the example file.
	************************************************************************** */
	void csvPaktReader(char layer2[], int l3DstAdrsLocation[], FILE *fptr)
	{
		char inputLine[42];
		fgets(inputLine, 42, fptr);
						
		int k = 0;
		int j = 0;
		int space = 0;
		int front = 0;
		int back = 0;

		for (j = 0; j < strlen(inputLine); j++)
		{
			if (inputLine[j] == ',')
			{
				continue;
			}
			else 
				if (inputLine[j] == ' ')
				{

					space = space + 1;
		
					if (space == 3)
					{
						front = k + 1;
					}
					if (space == 4)
					{
						back = k;
					}
					continue;	//PUTTING A CONTINUE IS CRITICAL

					}
			else
			{
				layer2[k] = inputLine[j];
			}

			k++;
		}

		layer2[k] = '\0';  //DOING THIS IS CRITICAL

		l3DstAdrsLocation[0] = front;
		l3DstAdrsLocation[1] = back;
		//return l3DstAdrsLocation;

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
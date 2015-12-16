/* *******************************
   Author: Okeke Nnadozie
   File Name: feedInputQueue.c
   ******************************************************************************************************
   Function: Contains the implementation for feedInputQueues
   ****************************************************************************************************** */
#include <string.h>
#include <stdio.h>



/*	****************************************************************
	feedInputQueues reads in all valid packets from the example file
	and queues all of them in their respective input queues.
	**************************************************************** */
	void feedInputQueues()
	{
		//char srcAdrs;
		enum inputQueues {inptQA, inptQB, inptQC, inptQD, inptQE};
		int l3DstAdrsLocation[2];
   		char layer2[32];
   		char l2PayLoad[30];
		int i, inptQSize;
		int l2SrcAdrs;
		
		for(i = 0; i < 11; i++)
		{
			create(i);
		}

		puts("Enter input queue size"); //make robust so only ints can be entered
		scanf("%d", &inptQSize);

   		char waste = getchar();
   		puts("Enter words separated by commas\n");

   		int eof = 1;

   		//while(eof != 0)
   		//{
	   		csvPaktReader(layer2, l3DstAdrsLocation);
	   		l2PayLoadExtractor(layer2, l2PayLoad);
	   	
	   		//l2SrcAdrs = layer2[0];
	   		//printf("%c\n", layer2[0]);

	   		switch (layer2[0])
	   		{
	   		case 'A':
		   		if(queueSize(inptQA) < inptQSize)
		   		{
		   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQA);
		   		}
		   		break;
		   	case 'B':
		   		if(queueSize(inptQB) < inptQSize)
		   		{
		   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQB);
		   		}
		   		break;
		   	case 'C':
		   		if(queueSize(inptQC) < inptQSize)
		   		{
		   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQC);
		   		}
		   		break;
		   	case 'D':
		   		if(queueSize(inptQD) < inptQSize)
		   		{
		   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQD);
		   		}
		   		break;
		   	case 'E':
		   		if(queueSize(inptQE) < inptQSize)
		   		{
		   			enqueue(layer2[0], layer2[1], l2PayLoad, inptQE);
		   		}
		   		break;
		   	default:
		   		puts("Error: Source address is invalid");
		   		break;
		   	}//end switch

   		//}

	}
//end feedInputQueues



/*	**************************************************************************
	csvPaktReaderis used for reading in layer 2 packets from the example file.
	************************************************************************** */
	void csvPaktReader(char layer2[], int l3DstAdrsLocation[])
	{
		char inputLine[42];
		//char l3DstAdrsLocation[2];
		fgets(inputLine, 42, stdin);
						
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
		for (k = 0; k < strlen(layer2); k++)
		{
			l2PayLoad[k] = layer2[k + 2];
		}

		#ifdef DEBUG
			puts(l2PayLoad);
		#endif

		return;
	}
//end layer2payload extractor

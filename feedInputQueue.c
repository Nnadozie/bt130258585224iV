/* *******************************
   Author: Okeke Nnadozie
   File Name: feedInputQueues.c
   ******************************************************************************************************
   Function: Contains the implementation for feedInputQueues
   ****************************************************************************************************** */
#include <string.h>
#include <stdio.h>


/*	**************************************************************************
	This function belongs in feeder program, and is to be used for reading in the 
	example file. It is employed here for testing purposes.
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
	L2PAYLOAD extractor. Also belongs in 
	feeder.
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

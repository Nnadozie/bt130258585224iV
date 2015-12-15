/* *******************************
   Author: Okeke Nnadozie
   Function Name: testInputQueue
   ******************************************************************************************************
   Function: testInputQueues is used to test the functionality of inputQueue
   ****************************************************************************************************** */

#include <stdio.h>
#include <string.h>
//#define DEBUG
#define MAIN

void csvPaktReader(char layer2[], int l3DstAdrsLocation[]);
void l2PayLoadExtractor(char layer2[], char l2payload[]);



/* *************
   MAIN FUNCTION
   ************* */
   void main()
   {
   		int choice, control; //k, j, space, front, back;;
   		
   		char srcAdrs;
   		//char inputLine[42];
   		int l3DstAdrsLocation[2];
   		char layer2[32];
   		char l2PayLoad[30];			

   		printf("1 - Enqueue\n");
   		printf("2 - Dequeue\n");
   		printf("3 - Queue Size\n");
   		printf("4 - Display queue\n");
   		printf("5 - stop and exit\n");
   		create();

   		control = 1;
   		while(control)
   		{

	   		printf("Enter choice: \n");
	   		scanf("%d", &choice);

	   		switch (choice)
	   		{
	   		case 1:
	   			printf("Enter data: \n");
	   			srcAdrs = getchar();	/*I've used a getchar() to store unwanted inputs which may affect scanf() or fgets()*/
	   			puts("Enter words separated by commas\n");
				csvPaktReader(layer2, l3DstAdrsLocation);

	   			#ifdef DEBUG
	   				puts(layer2);
	   				printf("%d %d\n", l3DstAdrsLocation[0], l3DstAdrsLocation[1]);
	   			#endif

	   			l2PayLoadExtractor(layer2, l2PayLoad);

	   			#ifdef MAIN
	   				puts(layer2);
	   				puts(l2PayLoad);
	   			#endif

	   			enqueue(layer2[0], layer2[1], l2PayLoad);
	   			break;
	   		case 2:
	   			dequeue();
	   			break;
	   		case 3:
	   			printf("The queue has %d nodes.\n", queueSize());
	   			break;
	   		case 4:
	   			display();
	   			break;
	   		case 5:
	   			//I need to empty the queue on exit
	   			control = 0;
	   		default:
	   			break;

	   		}//end queue control switch statement

   		}//end queue control while loop

   }
   //end main()



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
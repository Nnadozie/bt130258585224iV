/* *******************************
   Author: Okeke Nnadozie
   Function Name: testInputQueue
   ******************************************************************************************************
   Function: testInputQueues is used to test the functionality of inputQueue
   ****************************************************************************************************** */

#include <stdio.h>
#include <string.h>
#define DEBUG


/* *************
   MAIN FUNCTION
   ************* */
   void main()
   {
   		int choice, control, k, j, space, front, back;;
   		
   		char srcAdrs;
   		char inputLine[42];
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



	   			/*	**************************************************************************
	   				This function belongs in feeder program, and is to be used for reading in the 
	   				example file. It is employed here for testing purposes.
	   				************************************************************************** */
	   				puts("Enter words separated by commas\n");
					fgets(inputLine, 42, stdin);
					
					k = 0;
					space = 0;
					front = 0;
					back = 0;

					for (j = 0; j < strlen(inputLine); j++)
					{
						if (inputLine[j] == ',')
						{
							continue;
						}
						else if (inputLine[j] == ' ')
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
					
				//end layer2 packet reader.



				/*	*************************************
					L2PAYLOAD extractor. Also belongs in 
					feeder.
					************************************* */
					for (k = 0; k < strlen(layer2); k++)
					{
						l2PayLoad[k] = layer2[k + 2];
					}
				//end layer2payload extractor


				#ifdef DEBUG
					puts(inputLine);
					puts(layer2);
					printf("%d %d\n", front, back);
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
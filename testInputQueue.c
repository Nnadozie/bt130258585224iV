/* *******************************
   Author: Okeke Nnadozie
   Function Name: testInputQueue
   ******************************************************************************************************
   Function: testInputQueues is used to test the functionality of inputQueue
   ****************************************************************************************************** */

#include <stdio.h>
#include <string.h>
//#define DEBUG


/* *************
   MAIN FUNCTION
   ************* */
   void main()
   {
   		char srcAdrs;
   		int choice, control;
   		
   		int i, j, chars, space, front, back;
   		char inputLine[42];
   		char layer2[32];
   		char l2PayLoad[30];			

   		i = 0; 
   		space = 0;
   		front = 0;
   		back = 0;
   		chars = -1; //This is set to count character locations in an array, therefore for the first
   					//increment to correlate with the first position of the array, the count must begin from -1
		
   		control = 1;

   		printf("1 - Enqueue\n");
   		printf("2 - Dequeue\n");
   		printf("3 - Queue Size\n");
   		printf("4 - Display queue\n");
   		printf("5 - stop and exit\n");
   		create();

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
	   				This function belongs in feeder program, and is used for reading in the 
	   				example file. It is employed here for testing purposes.
	   				************************************************************************** */
	   				//int i = 0; 			;remember to delete these line duplicates that are above
					//char word[100];
					puts("Enter words separated by commas\n");
					fgets(inputLine, 42, stdin);

					while(inputLine[i] != '\0')
					{

						if (inputLine[i] == ',')
						{	
							//chars++; 
						}
						else if(inputLine[i] == ' ')
						{	

							//chars++;
							space++;

							if (space == 3)
							{ front = chars + 1; }

							if (space == 4)
							{ back = chars; }

						}
						else
						{

							chars++;
							layer2[chars] = inputLine[i];
							//printf("%c", word[i]);

						}

						i++;
					}
				//end function that belongs to feeder program.



				/* 	************************************
					This function also belongs to feeder.
					it extracts layer2's payload and stores
					it in an array of characters.
					************************************ */
				for (j = 0; j < 30; j++)
				{
					l2PayLoad[j] = layer2[j+2];
				}
				// end layer2 payload extractor

				#ifdef DEBUG
				{
					printf("%s", l2PayLoad);
				}
				puts(layer2);
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
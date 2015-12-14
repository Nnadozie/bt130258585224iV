/* *******************************
   Author: Okeke Nnadozie
   Function Name: testInputQueue
   ******************************************************************************************************
   Function: testInputQueues is used to test the functionality of inputQueue
   ****************************************************************************************************** */

#include <stdio.h>



/* *************
   MAIN FUNCTION
   ************* */
   void main()
   {
   		char srcAdrs;
   		// dstAdress, l2PayLoad[30];
   		int choice, control;

   		control = 1;

   		printf("1 - Enqueue\n");
   		printf("2 - Dequeue\n");
   		printf("3 - Queue Size\n");
   		printf("4 - Display queue\n");
   		printf("5 - stop and exit\n");
   		create();

   		while(control)
   		{

	   		printf("\nEnter choice: ");
	   		//scanf("%d", &choice);
	   		scanf("%d", &choice);

	   		switch (choice)
	   		{
	   		case 1:
	   			printf("Enter data: ");
	   			srcAdrs = getchar(); // I've used a getchar() to store unwanted inputs which may affect scanf()
	   			scanf("%c", &srcAdrs); /* Employ the use of conversion specifiers */
	   			enqueue(srcAdrs);
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
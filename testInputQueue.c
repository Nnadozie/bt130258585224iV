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
   		int no, control, choice;

   		//control = 1;

   		printf("1 - Enqueue\n");
   		printf("2 - Dequeue\n");
   		printf("3 - Queue Size\n");
   		printf("4 - Display queue\n");
   		create();

   		while(1)
   		{

	   		printf("\nEnter choice: ");
	   		scanf("%d", &choice);

	   		switch (choice)
	   		{
	   		case 1:
	   			printf("Enter data: ");
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
	   		default:
	   			break;
	   		}//end queue control switch statement

	   		//printf("0 - Stop , 1 - continue\n");
	   		//scanf("%d", &control);

   		}//end queue control while loop

   }
   //end main()
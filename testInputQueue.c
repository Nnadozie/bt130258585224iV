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
   		char srcAdrs, dstAdress, l2PayLoad[30];
   		int no, control, choice;

   		control = 1;

   		printf("1 - Enqueue\n");
   		printf("2 - Dequeue\n");
   		printf("3 - Queue Size\n");
   		printf("4 - Display queue\n");
   		create();

   		while(control)
   		{

	   		printf("\nEnter choice\n:\n");
	   		scanf("%d", &choice);

	   		switch (choice)
	   		{
	   		case 1:
	   			printf("Enter data :");
	   			scanf("%c%c%s", &srcAdrs, &dstAdress, l2PayLoad); /* Employ the use of conversion specifiers */
	   			enqueue(srcAdrs, dstAdress, l2PayLoad);
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
	   		}//end queue control switch statement

	   		printf("1 - Continue\n");
	   		scanf("%d", &control);

   		}//end queue control while loop

   }
   //end main()
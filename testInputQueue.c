/* *******************************
   Author: Okeke Nnadozie
   Function Name: testInputQueue
   ******************************************************************************************************
   Function: testInputQueues is used to test the functionality of inputQueue
   ****************************************************************************************************** */

	#include <stdio.h>
	#include <string.h>
	//#define DEBUG
	//#define MAINDEBUG



/*	*************
   	MAIN FUNCTION
   	************* */
   	void main()
   	{
   		int choice, control, Q;
   		char waste;	
   		feedInputQueues();

   	/*	************************************
   		User interface for debugging queues.
   		************************************ */
   		control = 1;
   		while(control)
   		{ 	
	   		puts("Choose queue:");
	   		puts("0 - inputQueueA");
	   		puts("1 - inputQueueB");
	   		puts("2 - inputQueueC");
	   		puts("3 - inputQueueD");
	   		puts("4 - inputQueueE");
	   		scanf("%d", &Q);
	   		waste = getchar();

	   		printf("1 - Dequeue\n");
	   		printf("2 - Queue Size\n");
	   		printf("3 - Display queue\n");
	   		printf("4 - stop and exit\n");
	   		printf("Enter choice: \n");
	   		scanf("%d", &choice);
	   		waste = getchar();


	   		switch (choice)
	   		{
	   		case 1:
	   			dequeue(Q);
	   			break;
	   		case 2:
	   			printf("The queue has %d nodes.\n", queueSize(Q));
	   			break;
	   		case 3:
	   			display(Q);
	   			break;
	   		case 4:
	   			//I need to empty the queue on exit
	   			control = 0;
	   		default:
	   			break;
	   		}//end queue control switch statement

   		}//end queue control while loop
   	// end of debugging gui.

   	}
//end main()
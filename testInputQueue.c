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



/*	*************
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
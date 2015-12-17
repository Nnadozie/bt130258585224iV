/* *******************************
   Author: Okeke Nnadozie
   Function Name: testInputQueue
   ******************************************************************************************************
   Function: testInputQueues is used to test the functionality of inputQueue
   ****************************************************************************************************** */

	#include <stdio.h>
	#include <string.h>
  #include <stdlib.h>
  #include <externVariables.h>
	//#define DEBUG
	//#define MAINDEBUG



	void testerFunction(); 
/*	*************
   MAIN FUNCTION
	************* */
  	void main()
  	{
  	   
      /* **************************************************
         This piece of code sets the length of layer two's
         payload array.
         ************************************************** */
         int l2PayLoadLength;
         int out = 0;

         while(out == 0)
         {
            puts("Enter layer 2 pay load array length | Must not be > 30");
            scanf("%d", &l2PayLoadLength);

            if(l2PayLoadLength <= 30)
            {
               L2MAXLOAD = l2PayLoadLength;
               out = 1;
            }
            else
            {
               out = 0;
            }
         }
          
      //end setting of layer two array length.

  	feedInputQueues();
   	testerFunction();
   }
//end main()



/*  *********************************************
    Tester function;  part of the user interface
    and placed here for conveinience. I dont want 
    to include the structure header in the test conde 
    ************************************************* */
    void testerFunction()
    {
        //printf("%d\n", sizeof(front[0]->l2PayLoad));
        int choice, control, Q;
        char waste;
        struct l2Packet *deqdPakt;    
        //feedInputQueues();

    /*  ************************************
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
                deqdPakt = (struct l2Packet*) dequeue(Q);
                free(deqdPakt);
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
//end testerFunction()
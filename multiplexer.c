/* *******************************
   Author: Okeke Nnadozie
   File Name: multiplexer.c
   ******************************************************************************************************
   Function: multiplex input Queues onto the main queue using a round robin like system.
   ****************************************************************************************************** */

   #include <stdlib.h>
   #include <stdio.h>
   #include "multiplexer.h"
   #include "inputQueue.h"
   //#define DEBUGMULTIPLEX

   int numOfChecksOf[5];

/*	****************************************************
	Multiplexer function
	**************************************************** */
	void multiplexer(int inptQSize, int mainQSize)
   	{
   	/*	****************************************************************
   		Declaration of all of multiplexer's variables
   		**************************************************************** */
   		enum inputQueues {inptQA, inptQB, inptQC, inptQD, inptQE, mainQ};
   		//int inputQueue[5] = {inptQA, inptQB, inptQC, inptQD, inptQE}; //for ease of understanding for loop
   		int dequedInputQ, loopControl, i;
   		char waste;
        struct l2Packet *deqdPakt;
        //deqdPakt = malloc(sizeof(struct l2Packet) + inptQSize);    
    //end variable declaration

        #ifdef DEBUGMULTIPLEX
        	puts("I got here");
        #endif
    /* 	********************************************************
    	Choose which input queue to dequeue onto the main queue.
    	Choice depends on size of input queues
    	******************************************************** */
		for (i = 0; i < inptQE; i++)
		{
			if(queueSize(i) == inptQSize)
			{
				dequedInputQ = i;
				break;
			}
			else if(queueSize(i) < inptQSize)
			{
				numOfChecksOf[i]++;

				#ifdef DEBUGMULTIPLEX
				printf("%d\n", numOfChecksOf[i] );
				#endif

				if(numOfChecksOf[i] == inptQSize)
				{
					dequedInputQ = i;
					numOfChecksOf[i] = 0;

					#ifdef DEBUGMULTIPLEX
        				puts("I got in this if");
        			#endif
        			break;
				}
				else
				{ //return;
				}
				//break;

			}
		}

		/*	else if(queueSize(inptQB) == inptQSize)
			{
				dequedInputQ = inptQB;
				//break;
			}
			else if(queueSize(inptQB) < inptQSize)
			{
				numOfChecksOf[inptQB]++;

				if(numOfChecksOf[inptQB] == inptQSize)
				{
					dequedInputQ = inptQB;
					numOfChecksOf[inptQB] = 0;
				}
				else
				{ return; };
			}

			else if(queueSize(inptQC) == inptQSize)
			{
				dequedInputQ = inptQC;
				//break;
			}
			else if(queueSize(inptQC) < inptQSize)
			{
				numOfChecksOf[inptQC]++;

				if(numOfChecksOf[inptQC] == inptQSize)
				{
					dequedInputQ = inptQC;
					numOfChecksOf[inptQC] = 0;
				}
				else
				{ return; };
			}

			else if(queueSize(inptQD) == inptQSize)
			{
				dequedInputQ = inptQD;
				//break;
			}
			else if(queueSize(inptQD) < inptQSize)
			{
				numOfChecksOf[inptQD]++;

				if(numOfChecksOf[inptQD] == inptQSize)
				{
					dequedInputQ = inptQD;
					numOfChecksOf[inptQD] = 0;
				}
				else
				{ return; }
			}

			else if(queueSize(inptQE) == inptQSize)
			{
				dequedInputQ = inptQE;
				//break;
			}
			else if(queueSize(inptQE) < inptQSize)
			{
				numOfChecksOf[inptQE]++;

				if(numOfChecksOf[inptQE] == inptQSize)
				{
					dequedInputQ = inptQE;
					numOfChecksOf[inptQE] = 0;
				}
				else
				{ return; }
			}*/
		
		



			/*else if(queueSize(inptQB) > 0)
			{dequedInputQ = inptQB;}

			else if(queueSize(inptQC) > 0)
			{dequedInputQ = inptQC;}

			else if(queueSize(inptQD) > 0)
			{dequedInputQ = inptQD;}

			else if(queueSize(inptQE) > 0)
			{dequedInputQ = inptQE;}*/

	//end choosing

        #ifdef DEBUGMULTIPLEX
        	puts("I got here too");
        #endif
	/*	***********************************************
		Dequeue the chosen input queue.
		************************************************ */
			switch (dequedInputQ)
			{
		  	case inptQA:

		   		if(queueSize(mainQ) < mainQSize)
		   		{
		   			deqdPakt = (struct l2Packet*) dequeue(inptQA);
		   			if(deqdPakt == NULL)
		   			{break;}
		   			enqueue(deqdPakt->srcAdrs, deqdPakt->dstAdrs, deqdPakt->l2PayLoad, mainQ);
		   			free(deqdPakt);
		   		}
		   		break;

		   	case inptQB:

		   		if(queueSize(mainQ) < mainQSize)
		   		{
		   			deqdPakt = (struct l2Packet*) dequeue(inptQB);
		   			if(deqdPakt == NULL)
		   			{break;}
		   			enqueue(deqdPakt->srcAdrs, deqdPakt->dstAdrs, deqdPakt->l2PayLoad, mainQ);
		   			free(deqdPakt);
			   	}
		   		break;

		   	case inptQC:

		   		if(queueSize(mainQ) < mainQSize)
		   		{
		   			deqdPakt = (struct l2Packet*) dequeue(inptQC);
		   			if(deqdPakt == NULL)
		   			{break;}
		   			enqueue(deqdPakt->srcAdrs, deqdPakt->dstAdrs, deqdPakt->l2PayLoad, mainQ);
		   			free(deqdPakt);
		   		}
		   		break;

		   	case inptQD:

		   		if(queueSize(mainQ) < mainQSize)
		   		{
		   			deqdPakt = (struct l2Packet*) dequeue(inptQD);
		   			if(deqdPakt == NULL)
		   			{break;}
		   			enqueue(deqdPakt->srcAdrs, deqdPakt->dstAdrs, deqdPakt->l2PayLoad, mainQ);
		   			free(deqdPakt);
		   		}
		   		break;

		   	case inptQE:

		   		if(queueSize(mainQ) < mainQ)
		   		{
		   			deqdPakt = (struct l2Packet*) dequeue(inptQE);
		   			if(deqdPakt == NULL)
		   			{break;}
		   			enqueue(deqdPakt->srcAdrs, deqdPakt->dstAdrs, deqdPakt->l2PayLoad, mainQ);
		   			free(deqdPakt);		
		   		}
		   		break;	

		   	default:
		   		puts("Error: Input Queue chosen does not exist or invalid option.");
		   		break;
		 	}//end switch
   }
//end multiplexer()
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


/*	****************************************************
	Multiplexer function
	**************************************************** */
	void multiplexer(int mainQSize)
   	{
   	/*	****************************************************************
   		Declaration of all of multiplexer's variables
   		**************************************************************** */
   		enum inputQueues {inptQA, inptQB, inptQC, inptQD, inptQE, mainQ};
   		int dequedInputQ, loopControl;
   		char waste;
        struct l2Packet *deqdPakt;
        //deqdPakt = malloc(sizeof(struct l2Packet) + L2MAXLOAD);    
    //end variable declaration


    /* 	********************************************************
    	Choose which input queue to dequeue onto the main queue.
    	Choice depends on size of input queues
    	******************************************************** */
		
			if(queueSize(inptQA) > 0)
			{dequedInputQ = inptQA;}

			else if(queueSize(inptQB) > 0)
			{dequedInputQ = inptQB;}

			else if(queueSize(inptQC) > 0)
			{dequedInputQ = inptQC;}

			else if(queueSize(inptQD) > 0)
			{dequedInputQ = inptQD;}

			else if(queueSize(inptQE) > 0)
			{dequedInputQ = inptQE;} 

	//end choosing


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
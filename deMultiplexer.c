/* *******************************
   Author: Okeke Nnadozie
   File Name: deMultiplexer.c
   ******************************************************************************************************
   Function: deMultiplex packets from the main queue to their output Queues.
   ****************************************************************************************************** */

     /*	***********************************************
   		*******Definition of layer 3 structure*********
   		NOTE: Layer 3's packet is the payload of layer 2.
   		It is stored in an array of defineable length
   		using the extern variable L2MAXLOAD
   		*********************************************** 
		Structure of L2PAYLOAD[L2MAXLOAD]
		L2PAYLOAD[0][1]: Layer 3 source address  //needs to be changed to an int
		L2PAYLOAD[2][3]: Layer 3 destination address // also needs to be changed to an int
		L2PAYLOAD[4]: priority
		L2PAYLOAD[5] and above: Layer 3 payload 
		
		Having sorted it this way, I don't see the need to 
		use a struct definition for layer 3's packet.
//	************************************************ */

	
	 #include <stdio.h>
	 #include "inputQueue.h"
	 #include <string.h>
	 #include <stdlib.h>
  // #define DEBUGDEMUL

  //int L2MAXLOAD;
  int numOfChecksOf[6];

   void deMultiplexer(int mainQSize)
   {

   	/*	***************************************************
   		Declaration of all variables needed for demultiplexer
   		***************************************************** */
   		enum inputQueues { mainQ = 5, outPtQA, outPtQB, outPtQC, outPtQD, outPtQE };	
   		struct l2Packet *deqdPakt = NULL;
   		int srcAdrsL3, dstAdrsL3, L3MAXLOAD, l2PayLoadLen,i;
   		char l3SrcAdrs[3] = {'0','0','\0'};
   		char l3DstAdrs[3] = {'0','0', '\0'};
   		char *l3Payload = NULL;
   		FILE *fptr;
   	//end declaration


    /* ****************************************************
       return after doing nothing if main queue is empty, but
       increment the no. of times that main queue has been 
       checked.
       **************************************************** */
      if (queueSize(mainQ) == 0)
      {
        numOfChecksOf[mainQ]++;

        #ifdef DEBUGDEMUL
        printf("if no of checks: %d\n", numOfChecksOf[mainQ] );
        display(mainQ);
        #endif

        return;
      }
      else
      {
    //end 


    /* ************************************************************
        if main queue has packets, check to see if buffer is full.
        if it is, dequeue.
        if it isn't, keep track of how long it remains unfull.
        if it's remains unfull for a certain amount of time, dequeue.
       ************************************************************** */
        numOfChecksOf[mainQ]++;

        #ifdef DEBUGDEMUL  
        printf("num of checks: %d\n", numOfChecksOf[mainQ] );
        display(mainQ); 
        puts("I got here in deMultiplexer");
        #endif


        if(queueSize(mainQ) == mainQSize)
        {
          deqdPakt = (struct l2Packet*) dequeue(mainQ);  //!!!!Remember to free deqdPakt
          numOfChecksOf[mainQ] = 0;

        }
        else if(queueSize(mainQ) < mainQSize)
        {
          if(numOfChecksOf[mainQ] == mainQSize)
          {
            deqdPakt = (struct l2Packet*) dequeue(mainQ);
            numOfChecksOf[mainQ] = 0;
          }

        }
    // end

        #ifdef DEBUGDEMUL
        puts("I also got here in deMultiplexer");
        #endif


       /*	*****************EXTRACT LAYER 3 PACKET*******************

       		**********************************************************
          -Go ahead to extract l3 packet from l2 packet, only if the de-
          queued packet has information in it.
       		layer 3 source and destination address are converted from 
       		characters to integers
    		  ********************************************************** */
        if ( deqdPakt != NULL)
        {
       		l3SrcAdrs[0] = deqdPakt->l2PayLoad[0];
       		l3SrcAdrs[1] = deqdPakt->l2PayLoad[1];
       		sscanf(l3SrcAdrs, "%d", &srcAdrsL3);

       		l3DstAdrs[0] = deqdPakt->l2PayLoad[2];
       		l3DstAdrs[1] = deqdPakt->l2PayLoad[3];
          dstAdrsL3 = atoi(l3DstAdrs);

      	//end conversion
          #ifdef DEBUGDEMUL
          puts("I got here as well in deMultiplexer");
          #endif


      	/*	******************************************
      		Extract layer 3's payload:
          copy the portion of layer 2's payload, which contains
          layer 3's payload, into the array which stores layer
          3's payload
      		****************************************** */
      		l2PayLoadLen = strlen(deqdPakt->l2PayLoad);

          #ifdef DEBUGDEMUL
          puts(deqdPakt->l2PayLoad);
          #endif

      		L3MAXLOAD = 25; //Max size = 25 //make global and initialize same time as L2MAXLOAD
      		l3Payload = (char *) malloc(sizeof(char) * (L3MAXLOAD));

      		for (i = 0; i <= l2PayLoadLen - 5; i++)
      		{
      				l3Payload[i] = deqdPakt->l2PayLoad[i+5];
      		}
      	//end extraction of payload*/
      //*******************END L3 PACKET EXTRACTION*************
        

          #ifdef DEBUGDEMUL
          puts("I got here in deMultiplexer, past payload extraction");
          printf("%s\n", deqdPakt->l2PayLoad);   
          free(deqdPakt);
          #endif
          printf("Source address: %d | destination address: %d | %s\n", srcAdrsL3, dstAdrsL3, l3Payload);

      }
      else //if the dequeued packet was empty, return without doing anything.
      {
        return;
      }

    }//end the other else

   }
//end deMultiplexer


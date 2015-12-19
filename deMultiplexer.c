/* *******************************
   Author: Okeke Nnadozie
   File Name: deMultiplexer.c
   ******************************************************************************************************
   Function: deMultiplex input Queues onto the main queue using a round robin like system.
   ****************************************************************************************************** */

     /*	***********************************************
   		*******Definition of layer 3 structure*********
   		NOTE: Layer 3 packet is the payload of layer 2.
   		It is stored in an array of defineable length
   		using the extern variable L2MAXLOAD
   		*********************************************** 
		Structure of L2PAYLOAD 
		[0][1]: Layer 3 source address  //need to be changed to an int
		[2][3]: Layer 3 destination address // also needs to be changed to an int
		[4]: priority
		[5] and above: Layer 3 payload 
		
		Having sorted it this way, I don't see the need to 
		use a struct definition for layer 3 packet.
   		************************************************ */

	
	#include <stdio.h>
	#include "inputQueue.h"
	#include <string.h>
	#include <stdlib.h>

   //int L2MAXLOAD;

   void deMultiplexer()
   {
   	/*	******************************************
   		Declare variables needed for demultiplexer
   		******************************************* */
   		enum inputQueues { mainQ = 5, outPtQA, outPtQB, outPtQC, outPtQD, outPtQE };	
   		struct l2Packet *deqdPakt = NULL;
   		int srcAdrsL3, dstAdrsL3, L3MAXLOAD, l2PayLoadLen,i;
   		char l3SrcAdrs[2];
   		char l3DstAdrs[2];
   		char *l3Payload = NULL;
   		FILE *fptr;
   	//end declaration

		deqdPakt = (struct l2Packet*) dequeue(mainQ);

   	/*	*****************EXTRACT LAYER 3 PACKET*******************
   		**********************************************************
   		convert layer 3 source and destination address from 
   		characters to integers
		********************************************************** */
   		l3SrcAdrs[0] = deqdPakt->l2PayLoad[0];
   		l3SrcAdrs[1] = deqdPakt->l2PayLoad[1];
   		sscanf(l3SrcAdrs, "%d", &srcAdrsL3);

   		l3DstAdrs[0] = deqdPakt->l2PayLoad[2];
   		l3DstAdrs[1] = deqdPakt->l2PayLoad[3];
   		sscanf(l3DstAdrs, "%d", &dstAdrsL3);

  	//end conversion

  	/*	******************************************
  		Extract layer 3's payload
  		****************************************** */
  		l2PayLoadLen = strlen(deqdPakt->l2PayLoad);
  		L3MAXLOAD = 25; //Max size = 25 //make global and initialize same time as L2MAXLOAD
  		l3Payload = (char *) malloc(sizeof(char) * (L3MAXLOAD));

  		for (i = 0; i <= l2PayLoadLen - 5; i++)
  		{
  			//if(i <= sizeof(l3Payload))
  			{
  				l3Payload[i] = deqdPakt->l2PayLoad[i+5];
  			}
  			//else
  			{
  			//	continue;
  			}
  		}

  		/*if( sizeof(l3Payload) > l2PayLoadLen)
  		{
  			l3Payload[l2PayLoadLen+1] = '\0';
  		}*/
  	//end extraction


   		printf("Source address: %d | destination address: %d | %s\n", srcAdrsL3, dstAdrsL3, l3Payload);


   		//l3Payload = (char *) malloc(sizeof(char) * (L3MAXLOAD));
   }

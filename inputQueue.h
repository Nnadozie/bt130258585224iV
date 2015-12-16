/* *******************************
   Author: Okeke Nnadozie
   File Name: inputQueue.h
   ******************************************************************************************************
   Function: inputQueue header file
   ****************************************************************************************************** */
  // #define NUMOFQUEUES 11


/* ********************************
    Structure of the layer 2 packet
    ******************************* */
    struct l2Packet    
    {

        char srcAdrs;   //source address
        char dstAdrs;   //destination address
        char l2PayLoad[L2MAXLOAD]; 
        struct l2Packet *ptr;

    } *front[11], *rear[11], *temp[11], *front2[11];
//end l2packet

  void enqueue(char srcAdrs, char dstAdrs, char l2PayLoad[], int packDstQ); /* consider how you'll make the argument into a single sturcture argument that can be passed at a go*/
  void dequeue(int packDstQ);
  void create(int packDstQ);
  int queuesize(int packDstQ);
  void display(int packDstQ);
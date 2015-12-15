/* *******************************
   Author: Okeke Nnadozie
   File Name: inputQueue.h
   ******************************************************************************************************
   Function: inputQueue header file
   ****************************************************************************************************** */



/* ********************************
    Structure of the layer 2 packet
    ******************************* */
    struct l2Packet    
    {

        char srcAdrs;   //source address
        char dstAdrs;   //destination address
        char l2PayLoad[L2MAXLOAD]; 
        struct l2Packet *ptr;

    }*front, *rear, *temp, *front2;
//end l2packet

void enqueue(char srcAdrs, char dstAdrs, char l2PayLoad[]); /* consider how you'll make the argument into a single sturcture argument that can be passed at a go*/
void dequeue();
void create();
int queuesize();
void display();
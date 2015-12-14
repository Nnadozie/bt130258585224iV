/* *******************************
   Author: Okeke Nnadozie
   Function Name: inputQueue
   ******************************************************************************************************
   Function: inputQueue contains the implementation of the input queues to the router, which need to have
   a configurable maximum length, and be capable of storing the defined packets.
   ****************************************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define L2MAXLOAD 30



/* ********************************
    Structure of the layer 2 packet
    ******************************* */
struct l2Packet    
{

    char srcAdrs;   //source address
    char dstAdrs;   //destination address
    char l2payload[L2MAXLOAD]; 
    struct l2Packet *ptr;

}*front, *rear, *temp, *front2
//end l2packet



/*  ***************************
    create makes an empty queue
    *************************** */
void create()
{
    front = rear = NULL;
}
//end create()



/*  ***************************************************
    enqueue adds a new node to the bottom of the queue
    *************************************************** */
void enqueue(char srcAdrs, char dstAdrs, char l2payload[])
{

    if (rear == NULL)
    {
        rear = (struct l2Packet *) malloc(sizeof(struct l2Packet));
        rear->ptr = NULL;
        rear->srcAdrs = srcAdrs;
        rear->dstAdrs = dstAdrs;
        rear->l2payload = l2Packet  /*  I don't think this will work due to how strings operate.
                                        Find out how to use strCopy*/
        front = rear;
    }
    else
    {
        temp = (struct l2Packet *) malloc(sizeof(struct l2Packet));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr =NULL;

        rear = temp;
    }

} 
//end enqueue()


/*  ************************************************
    dequeue removes a node from the top of the queue
    ************************************************ */
void dequeue()
{
    front2 = front;

    if(front2 == NULL)
    {
        printf("Do nothing because queue is empty\n");
        return;
    }
    else
    {
        
    }
}


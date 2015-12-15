/* *******************************
   Author: Okeke Nnadozie
   Function Name: inputQueue
   ******************************************************************************************************
   Function: inputQueue contains the implementation of the input queues to the router, which need to have
   a configurable maximum length, and be capable of storing the defined packets.
   ****************************************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L2MAXLOAD 30
#include "inputQueue.h"
//#define DEBUG



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
    void enqueue(char srcAdrs, char dstAdrs, char l2PayLoad[]) /* consider how you'll make these arguments into a single sturcture argument that can be passed in a go*/
    {
        #ifdef DEBUG
            puts(l2PayLoad);
        #endif

        if (rear == NULL)
        {
            rear = (struct l2Packet *) malloc(sizeof(struct l2Packet));
            rear->ptr = NULL;
            rear->srcAdrs = srcAdrs;
            rear->dstAdrs = dstAdrs;
            strcpy(rear->l2PayLoad, l2PayLoad);  /*  make sure to include string library*/
            front = rear;
        }
        else
        {
            temp = (struct l2Packet *) malloc(sizeof(struct l2Packet));
            rear->ptr = temp;
            temp->srcAdrs = srcAdrs;
            temp->dstAdrs = dstAdrs;
            strcpy(temp->l2PayLoad, l2PayLoad);
            temp->ptr =NULL;

            rear = temp;
        }

        #ifdef DEBUG
        puts("I've loaded the structure");
        puts(rear -> l2PayLoad);
        #endif

    } 
//end enqueue()



/*  ************************************************
    dequeue removes a node from the top of the queue
    ************************************************ */
    void dequeue() /* This will have to return the structure so that it can be queued later on in the main queue*/

    {

        front2 = front;

        if(front2 == NULL)
        {
            printf("Do nothing because queue is empty\n");
            return;
        }
        else
            if (front2->ptr != NULL)
            {
                front2 =  front2->ptr;
                printf("Dequeued values: %c, %c, %s\n", front->srcAdrs, front->dstAdrs, front->l2PayLoad);
                free(front);
                front = front2;
            }
            else
            {
                printf("Dequeued values: %c, %c, %s\n", front->srcAdrs, front->dstAdrs, front->l2PayLoad);
                free(front);
                front = NULL;
                rear = NULL;
            }

    }
//end dequeue()



/*  *********************************
    Display the queue nodes
    ********************************* */
    void display()
    {

        front2 = front;

        if ((front2 == NULL) && (rear == NULL))
        {
            printf("Do nothing. Queue is empty\n");
            return;
        }
        while (front2 != rear)
        {
            printf("%c, %c, %s\n", front2->srcAdrs, front2->dstAdrs, front2->l2PayLoad);
            front2 = front2->ptr;
        }
        if (front2 == rear)
        {
            printf("%c, %c, %s\n", front2->srcAdrs, front2->dstAdrs, front2->l2PayLoad);
        }

    }
//end display()



/*  *************************************************
    queueSize counts the number of nodes in the queue
    ************************************************* */
    int queueSize()
    {

        int count = 0;
        front2 = front;

        if ((front2 == NULL) && (rear == NULL))
        {
            return count;
        }
        while (front2 != rear)
        {
            count++;
            front2 = front2->ptr;
        }
        if (front2 == rear)
        {
            count++;
        }

        return count;

    }
//end queueSize()
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
    //#define L2MAXLOAD 30
/*  #define NUMOFQUEUES 11: I tried to use this to set the no. of queues - 
    currently set at 11 in the inputQueue.h headerfile by setting all the struct
    l2packet pointers to 11 - but it seems #define only works in functions and 
    structures. */
    #include "inputQueue.h"
    //#define DEBUG
    int L2MAXLOAD;



/*  ***************************
    create makes an empty queue
    *************************** */
    void create(int packDstQ)
    {
        front[packDstQ] = rear[packDstQ] = NULL; //Read as front node of the queue that the packet is destined for gets the value...
    }
//end create()



/*  ***************************************************
    enqueue adds a new node to the bottom of the queue
    *************************************************** */
    void enqueue(char srcAdrs, char dstAdrs, char l2PayLoad[], int packDstQ) /* consider how you'll make these arguments into a single sturcture argument that can be passed in a go*/
    {
        #ifdef DEBUG
            puts(l2PayLoad);
        #endif

        char layer2PayLoad[L2MAXLOAD];

        if (rear[packDstQ] == NULL)
        {
            rear[packDstQ] = (struct l2Packet *) malloc(sizeof(struct l2Packet));
            rear[packDstQ]->ptr = NULL;
            rear[packDstQ]->srcAdrs = srcAdrs;
            rear[packDstQ]->dstAdrs = dstAdrs;
            rear[packDstQ]->l2PayLoad = layer2PayLoad;
            strcpy(rear[packDstQ]->l2PayLoad, l2PayLoad);  /*  make sure to include string library*/
            front[packDstQ] = rear[packDstQ];
        }
        else
        {
            temp[packDstQ] = (struct l2Packet *) malloc(sizeof(struct l2Packet));
            rear[packDstQ]->ptr = temp[packDstQ];
            temp[packDstQ]->srcAdrs = srcAdrs;
            temp[packDstQ]->dstAdrs = dstAdrs;
            temp[packDstQ]->l2PayLoad = layer2PayLoad;
            strcpy(temp[packDstQ]->l2PayLoad, l2PayLoad);
            temp[packDstQ]->ptr =NULL;

            rear[packDstQ] = temp[packDstQ];
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
    struct l2Packet* dequeue(int packDstQ) /* This will have to return the structure so that it can be queued later on in the main queue*/

    {
        struct l2Packet *deqdNode = NULL;
        front2[packDstQ] = front[packDstQ];

        if(front2[packDstQ] == NULL)
        {
            printf("Do nothing because queue is empty\n");
        }
        else
            if (front2[packDstQ]->ptr != NULL)
            {
                front2[packDstQ] =  front2[packDstQ]->ptr;
                front[packDstQ]->ptr = NULL;
                deqdNode = front[packDstQ];
                printf("Dequeued values: %c, %c, %s\n", front[packDstQ]->srcAdrs, front[packDstQ]->dstAdrs, front[packDstQ]->l2PayLoad);
                front[packDstQ] = front2[packDstQ];
            }
            else
            {
                deqdNode = front[packDstQ];
                printf("Dequeued values: %c, %c, %s\n", front[packDstQ]->srcAdrs, front[packDstQ]->dstAdrs, front[packDstQ]->l2PayLoad);
                front[packDstQ] = NULL;
                rear[packDstQ] = NULL;
            }

        return deqdNode;

    }
//end dequeue()



/*  *********************************
    Display the queue nodes
    ********************************* */
    void display(int packDstQ)
    {

        front2[packDstQ] = front[packDstQ];

        if ((front2[packDstQ] == NULL) && (rear[packDstQ] == NULL))
        {
            printf("Do nothing. Queue is empty\n");
            return;
        }
        while (front2[packDstQ] != rear[packDstQ])
        {
            printf("%c, %c, %s\n", front2[packDstQ]->srcAdrs, front2[packDstQ]->dstAdrs, front2[packDstQ]->l2PayLoad);
            front2[packDstQ] = front2[packDstQ]->ptr;
        }
        if (front2[packDstQ] == rear[packDstQ])
        {
            printf("%c, %c, %s\n", front2[packDstQ]->srcAdrs, front2[packDstQ]->dstAdrs, front2[packDstQ]->l2PayLoad);
        }

    }
//end display()



/*  *************************************************
    queueSize counts the number of nodes in the queue
    ************************************************* */
    int queueSize(int packDstQ)
    {

        int count = 0;
        front2[packDstQ] = front[packDstQ];

        if ((front2[packDstQ] == NULL) && (rear[packDstQ] == NULL))
        {
            return count;
        }
        while (front2[packDstQ] != rear[packDstQ])
        {
            count++;
            front2[packDstQ] = front2[packDstQ]->ptr;
        }
        if (front2[packDstQ] == rear[packDstQ])
        {
            count++;
        }

        return count;

    }
//end queueSize()



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
                deqdPakt = dequeue(Q);
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
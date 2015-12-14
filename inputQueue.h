/* *******************************
   Author: Okeke Nnadozie
   Function Name: inputQueue.h
   ******************************************************************************************************
   Function: inputQueue header file
   ****************************************************************************************************** */
 
struct l2Packet    
{

    char srcAdrs;   //source address
    char dstAdrs;   //destination address
    char l2payload[L2MAXLOAD]; 
    struct l2Packet *ptr;

}*front, *rear, *temp, *front2
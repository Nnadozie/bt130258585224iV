/* *******************************
   Author: Okeke Nnadozie
   Function Name: testInputQueue
   ******************************************************************************************************
   Function: testInputQueues is used to test the functionality of inputQueue
   ****************************************************************************************************** */

	#include <stdio.h>
	#include <string.h>
	//#define DEBUG
	//#define MAINDEBUG
   	//int L2MAXLOAD;
    #include <externVariables.h>
   	//const int L2MAXLOAD;


	//void testerFunction();
/*	*************
   	MAIN FUNCTION
   	************* */
   	void main()
   	{
   		//L2MAXLOAD = 30;
   		int i = 30;
   		L2MAXLOAD = i;
   		feedInputQueues();
   		testerFunction();
   	}
//end main()
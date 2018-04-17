/**************************************************************\
*                                                              *
* Name: main.c                                                 *
* Purpose:                                                     *
* This program will calculate the GCD using two user inputs    *
* Factor 1 and factor 2. It will then calculate the LCM using  *
* those inputs.                                                *
*                                                              *
*                                                              *
****************************************************************
* MODIFICATION HISTORY:                                        *
* 5/25/2017: Andrew Barsoom - created                           *
\**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
//Function prototypes
void flushKeyBoard();
int validation(int num, int status);
void gcd_lcm(int factor1 , int factor2 , int *gcd, int *lcm);
/********************************************************************\
*                                                                    *
* Name       : main()                                                *
* Parameters :                                                       *
* Returns    : int                                                   *
* Description:                                                       *
* This module prompts the user to enter the factors and calls on     *
* different functions                                                *
**********************************************************************
* MODIFICATION HISTORY                                               *
*                                                                    *
* 5/25/2017 - Andrew Barsoom - Created                               *
*                                                                    *
\********************************************************************/
int main() {
	int status, lcm = 0, factor1, factor2, gcd=0; //Variables to store input 
	printf("Enter Factor1: ");
	status = scanf("%d", &factor1); //scanf and return the status for validation
	factor1 = validation(factor1, status); // call validation function


	printf("Enter Factor2: ");
	status = scanf("%d", &factor2);//scanf and return the status for validation
	factor2 = validation(factor2, status);// call validation function



	gcd_lcm(factor1, factor2, &gcd, &lcm); //call gcd_lcm function to begin gcd calculation
	
	gcd_lcm(factor1, factor2, &gcd, &lcm);//call gcd_lcm function to begin lcd calculation

	printf("The GCD of %d and %d is %d. The LCM is %d \n", factor1, factor2, gcd, lcm); //print all variables after calculations.
	return 0;
}
/********************************************************************\
*                                                                    *
* Name       : gcd_lcm(int factor1, int factor2, int *gcd, int *lcm) *
* Parameters : int factor1, int factor2, int *gcd, int *lcm          *
* Returns    : factor1, lcm                                          *
* Description:                                                       *
* This module calculates the GCD using recursion and the LCM         *
*                                                                    *
**********************************************************************
* MODIFICATION HISTORY                                               *
*                                                                    *
* 5/25/2017 - Andrew Barsoom - Created                               *
*                                                                    *
\********************************************************************/
void gcd_lcm(int factor1, int factor2, int *gcd, int *lcm) {
	//Recursive function that will calculate the GCD, and then the LCM and return it.
	if (*gcd != 0) {//ensure it only calculates LCM when GCD is calculated
		int temp = *gcd; //copy into temp variables
		*lcm = (factor1 * factor2) / temp; //calculates LCM
	}else if (factor2 != 0) {//GCD calculating phase
		gcd_lcm(factor2, factor1%factor2, gcd, lcm);
	}
	else {
			*gcd = factor1;//copies the gcd
	}


	
}
/**************************************************************\
*                                                              *
* Name       : flushKeyBoard()                                 *
* Parameters : none                                            *
* Returns    : none                                            *
* Description:                                                 *
* This module empties the keyboard buffer so that the next     *
* time input is required there is no "old" data still present. *
*                                                              *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 5/25/2017 - Andrew Barsoom - Created                         *
*                                                              *
\**************************************************************/
void flushKeyBoard()
{
	int ch;  // A dummy variable to read data into

	while ((ch = getc(stdin)) != EOF && ch != '\n') //clear input buffer
		;
}
/**************************************************************\
*                                                              *
* Name       : validation(int num, int status)                 *
* Parameters : num, status                                     *
* Returns    : int                                             *
* Description:                                                 *
* Validates user input                                         *
*                                                              *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 5/25/2017 - Andrew Barsoom - Created                          *
*                                                              *
\**************************************************************/
int validation(int num, int status) {
	int temp;
	//Input validation function
	while (status != 1 || num <= 0) { //ensure that they didn't enter a numeric value
		while (status != 1) {
			while ((temp = getchar()) != EOF && temp != '\n');
			printf("Invalid number entered, please re-enter: "); //Ask for correct value
			status = scanf("%d", &num);

		}

		if (num <= 0) { //check if value is below 0, and print for another number.
			printf("Number must be an integer > 0, please re-enter: ");
			status = scanf("%d", &num);

		}
	}
	return num;
}
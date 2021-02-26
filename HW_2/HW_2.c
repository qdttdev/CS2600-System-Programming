/*******************************************************************************
 * Name:	Caroline Ta
 * Date:	03/02/2021
 * Class:	CS2600.02
 * HW:		Homework 2 - Column Sorter (Extra Credit)
 ******************************************************************************/
#include "header.h"

int main(int argNum, char** argList)
{
//	For testing command line parameters
//	printf("You have entered %d arguments", argNum);
//	printf("\nargList[0] = %s",argList[0]);
//	printf("\nargList[1] = %s",argList[1]);
//	printf("\nargList[2] = %s",argList[2]);

	// VARIABLES
	int colParam = atoi(argList[2]);
	struct Person pArr[5];
	FILE *fin;
	char fileName[] = "input.txt";

	printf("\n\nWELCOME TO COLUMN SORTER PROGRAM\n");
	printf("The entered sorted column is: %d", colParam);

	fin = fopen(fileName,"r"); // open file, read only

	if(fin == NULL)
	{
		printf("\n\nError - File does not exist.");
		exit(1);
	}
	else
	{
		printf("\n\nOpening file...\n\n");

		ReadInput(fin, pArr);
	}

	fclose(fin); // close file

	printf("\n\n------------------------------");
	printf("\nOUTPUT THE DATA BEFORE SORTING");
	printf("\n------------------------------");
	PrintData(pArr);

	BubbleSort(pArr,colParam);
	printf("\n\n------------------------------------------");
	printf("\nOUTPUT THE DATA AFTER SORTING BY COLUMN #%d", colParam);
	printf("\n------------------------------------------");
	PrintData(pArr);

	return 0;
}





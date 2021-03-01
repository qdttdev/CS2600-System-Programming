#include "header.h"

void CmdPrintHelper()
{
	printf("\n---------------------");
	printf("\nCOLUMN SORTER PROGRAM");
	printf("\n---------------------\n");
	printf("This program expects 2 integers on the command line.\n");
	printf("\nThe first integer determines the column to be sorted (1-3):");
	printf("\n\t1 - Name");
	printf("\n\t2 - Age");
	printf("\n\t3 - Fruit\n");
	printf("\nThe second integer determines the sorting algorithm used (0-4):");
	printf("\n\t0 - Bubble Sort");
	printf("\n\t1 - Insertion Sort");
	printf("\n\t2 - Merge Sort");
	printf("\n\t3 - Quick Sort");
	printf("\n\t4 - Selection Sort\n");
}


//	For testing command line parameters
//	printf("You have entered %d arguments", argNum);
//	printf("\nargList[0] = %s",argList[0]);
//	printf("\nargList[1] = %s",argList[1]);	// the column to be sorted
//	printf("\nargList[2] = %s",argList[2]);	// the sorting algorithm

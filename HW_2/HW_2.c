/*******************************************************************************
 * Name:	Caroline Ta
 * Date:	03/02/2021
 * Class:	CS2600.02
 * HW:		Homework 2 - Column Sorter (Extra Extra Extra Credit)
 ******************************************************************************/
#include "header.h"

int main(int argNum, char** argList)
{
	// CONSTANTS
	const char *sortAlgoArr[ROW_SIZE] = {"Bubble Sort",
										 "Insertion Sort",
										 "Merge Sort",
										 "Quick Sort",
										 "Selection Sort"};
	// VARIABLES
	int colParam = atoi(argList[1]);
	int sortParam = atoi(argList[2]);
	struct Person pArr[ROW_SIZE];
	FILE *fin;
	char fileName[] = "input.txt";

	if (argNum == 2 && (strcmp(argList[1], "-h") == 0))
	{
		CmdPrintHelper();
		return 0;
	}
	if (argNum != 3 || colParam > 3  || colParam < 1
					|| sortParam > 4 || sortParam < 0)
	{
		printf("INVALID INPUT\n");
		printf("Example usage: HW_2 1 0\n");
		printf("Enter -h in the command line to see parameters' conditions.\n");
		return 0;
	}



	printf("\nWELCOME TO COLUMN SORTER PROGRAM");
	printf("\nThe entered sorted column is: %d", colParam);
	printf("\nThe sorting algorithm chosen is: %s", sortAlgoArr[sortParam]);

	fin = fopen(fileName,"r"); // open file, read only

	if(fin == NULL)
	{
		printf("\n\nError - File does not exist.");
		exit(1);
	}
	else
	{
		printf("\n\nOpening file...\n");
		ReadInput(fin, pArr);
	}

	fclose(fin); // close file

	printf("\n------------------------------");
	printf("\nOUTPUT THE DATA BEFORE SORTING");
	printf("\n------------------------------");
	PrintData(pArr);

	printf("\n\nSorting using %s...",sortAlgoArr[sortParam]);

	switch(sortParam)
	{
		case BUBBLE_SORT:		BubbleSort(pArr,colParam);
			break;

		case INSERTION_SORT:	InsertionSort(pArr,colParam);
			break;

		case MERGE_SORT:		MergeSort(pArr,0,ROW_SIZE-1,colParam);
			break;

		case QUICK_SORT:		QuickSort(pArr,colParam);
			break;

		case SELECTION_SORT:	SelectionSort(pArr,colParam);
			break;
	}

	printf("\n\n------------------------------------------");
	printf("\nOUTPUT THE DATA AFTER SORTING BY COLUMN #%d", colParam);
	printf("\n------------------------------------------");
	PrintData(pArr);

	return 0;
}

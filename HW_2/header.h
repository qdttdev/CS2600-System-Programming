#ifndef HEADER_H_
#define HEADER_H_

#include <stdio.h>		// standard I/O functions
#include <stdbool.h>	// boolean
#include <string.h>		// strcmp
#include <stdlib.h>		// malloc

#define COL_SIZE 3
#define ROW_SIZE 5

struct Person
{
	char	name[100];
	int		age;
	char	fruit[100];
};

enum SortAlgorithm
{
	BUBBLE_SORT,
	INSERTION_SORT,
	MERGE_SORT,
	QUICK_SORT,
	SELECTION_SORT
};

// Function Declaration
void CmdPrintHelper();
int CompareByName(const void* a, const void* b);
int CompareByAge(const void* a, const void* b);
int CompareByFruit(const void* a, const void* b);
void Merge(struct Person arr[], int l, int m, int r, int sortBy);

void BubbleSort(struct Person pArr[], int sortBy);
void InsertionSort(struct Person pArr[], int sortBy);
void MergeSort(struct Person arr[], int l, int r, int sortBy);
void QuickSort(struct Person pArr[], int sortBy);
void SelectionSort(struct Person pArr[], int sortBy);

void ReadInput (FILE *fin, struct Person pArr[]);
void PrintData(struct Person pArr[]);

#endif /* HEADER_H_ */

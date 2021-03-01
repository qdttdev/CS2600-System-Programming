#include "header.h"

/******************************************************************************
 * BubbleSort
 * ----------------------------------------------------------------------------
 * This function will sort the array using Bubble Sort:
 * 		Compares adjacent elements of an array, swaps them if they are
 * 		out of order and repeat.
 *****************************************************************************/
void BubbleSort(struct Person pArr[], int sortBy)
{
	struct Person temp;
	int size = ROW_SIZE;
	bool colCmp;

	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - 1 - i; j++)
		{
			switch(sortBy)
			{
				case 1:		colCmp = strcmp(pArr[j].name, pArr[j+1].name) > 0;
							break;
				case 2:		colCmp = pArr[j].age > pArr[j+1].age;
							break;
				case 3:		colCmp = strcmp(pArr[j].fruit,pArr[j+1].fruit) > 0;
							break;
			}
			if(colCmp)
			{
				temp = pArr[j];
				pArr[j] = pArr[j+1];
				pArr[j+1] = temp;
			}
		}
	}
}

/******************************************************************************
 * InsertionSort
 * ----------------------------------------------------------------------------
 * This function will sort the array using Insertion Sort:
 * 		Passes through the array only once, sorts like you would sort a and of
 * 		cards: pick up one card, put it in the correct location, repeat.
 *****************************************************************************/
void InsertionSort(struct Person pArr[], int sortBy)
{
	{
		int i; 		// Index of the first sorted element
		int j; 		// Index of the element before temp
		struct Person temp;	// Temp for comparison
		bool colCmp;

		for(i = 1; i < ROW_SIZE; ++i)	// Sorting starts at 1 because we considered the
								// the first element a sorted array itself
		{
			temp = pArr[i]; // Temp for comparison, traverse through the list by i
			j 	 = i - 1;	// Index of the element before temp

			switch(sortBy)
			{
				case 1:		colCmp = strcmp(pArr[j].name,temp.name) > 0;
							break;
				case 2:		colCmp = pArr[j].age > temp.age;
							break;
				case 3:		colCmp = strcmp(pArr[j].fruit,temp.fruit) > 0;
							break;
			}

			// Checking if the element before is LARGER than current temp
			while(j >= 0 && colCmp)
			{
				pArr[j+1] = pArr[j];	// If so, swap them (moving largest to the right)
				j = j-1;		   		// Continue swapping with the next element
			}

			pArr[j+1] = temp;	// After swapping in WHILE loop, the proper position
								// for temp is now assigned here
		}
	}
}

/******************************************************************************
 * Merge
 * ----------------------------------------------------------------------------
 * This function will merge the 2 separated arrays that were sorted.
 *****************************************************************************/
void Merge(struct Person pArr[], int left, int mid, int right, int sortBy)
{
    int i = 0;
    int j = 0;
    int k = left;
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    bool colCmp;

    struct Person leftArr[leftSize];
    struct Person rightArr[rightSize];

    // Populate leftArr and rightArr from pArr
    for (int i = 0; i < leftSize; i++)
    {
    	leftArr[i] = pArr[left + i];
    }
    for (int j = 0; j < rightSize; j++)
    {
    	rightArr[j] = pArr[mid + 1 + j];
    }

    // Merge the leftArr and rightArr back into pArr
    while (i < leftSize && j < rightSize) 
    {
    	switch(sortBy)
    	{
    		case 1:		colCmp = strcmp(leftArr[i].name,rightArr[j].name) <= 0;
    					break;
    		case 2:		colCmp = leftArr[i].age <= rightArr[j].age;
    					break;
    		case 3:		colCmp = strcmp(leftArr[i].fruit,rightArr[j].fruit) <= 0;
    					break;
    	}
    	
        if (colCmp)
        {
            pArr[k] = leftArr[i];
            i++;
        }
        else
        {
            pArr[k] = rightArr[j];
            j++;
        }

        k++;
    }

    // Insert the remaining elements of leftArr
    while (i < leftSize)
    {
        pArr[k] = leftArr[i];
        i++;
        k++;
    }

    // Insert the remaining elements of rightArr
    while (j < rightSize)
    {
        pArr[k] = rightArr[j];
        j++;
        k++;
    }
}


/******************************************************************************
 * MergeSort
 * ----------------------------------------------------------------------------
 * This function will sort the array through merge sort.
 *****************************************************************************/
void MergeSort(struct Person pArr[], int left, int right, int sortBy)
{
    if (left < right) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        MergeSort(pArr, left, mid, sortBy);
        MergeSort(pArr, mid + 1, right, sortBy);

        Merge(pArr, left, mid, right, sortBy);
    }
}

/******************************************************************************
 * SelectionSort
 * ----------------------------------------------------------------------------
 * This function will sort the array using Selection Sort:
 *		Finds the largest value and puts it at the end, then checks the
 *		array-1 element, repeat.
 *****************************************************************************/
void SelectionSort(struct Person pArr[], int sortBy)
{
	struct Person larger;
	int index = 0;
	bool colCmp;

	for(int i = ROW_SIZE-1; i >= 1; --i) // Traverse through the entire list
	{
		larger = pArr[0]; // assume the first elem is the largest
		index  = 0;		 // index of the largest

		for(int j = 1; j <= i; ++j) // Traverse through the entire list from
									// 1 to array-1 element
		{
			switch(sortBy)
			{
				case 1:		colCmp = strcmp(pArr[j].name,larger.name) > 0;
							break;
				case 2:		colCmp = pArr[j].age > larger.age;
							break;
				case 3:		colCmp = strcmp(pArr[j].fruit,larger.fruit) > 0;
							break;
			}

			if(colCmp) // If current index is LARGER than the largest
			{
				larger = pArr[j];	// The largest value now is assigned to larger
				index = j;		 	// index now holds the index of the largest
			}
		}

		pArr[index] = pArr[i];	// The largest position is at the end of the list
		pArr[i] = larger;	 	// The largest value is assigned to the position
	}
}

/******************************************************************************
 * CompareByName
 * ----------------------------------------------------------------------------
 * This function is used in the Quick Sort to compare name values.
 *****************************************************************************/
int CompareByName(const void* a, const void* b)
{
	struct Person *ia = (struct Person*)a;
	struct Person *ib = (struct Person*)b;
	return strcmp(ia->name,ib->name);
}

/******************************************************************************
 * CompareByAge
 * ----------------------------------------------------------------------------
 * This function is used in the Quick Sort to compare age values.
 *****************************************************************************/
int CompareByAge(const void* a, const void* b)
{
	struct Person *ia = (struct Person*)a;
	struct Person *ib = (struct Person*)b;
	return (int)(ia->age - ib->age);
}

/******************************************************************************
 * CompareByFruit
 * ----------------------------------------------------------------------------
 * This function is used in the Quick Sort to compare fruit values.
 *****************************************************************************/
int CompareByFruit(const void* a, const void* b)
{
	struct Person *ia = (struct Person*)a;
	struct Person *ib = (struct Person*)b;
	return strcmp(ia->fruit,ib->fruit);
}

/******************************************************************************
 * QuickSort
 * ----------------------------------------------------------------------------
 * This function will sort the array using Quick Sort.
 *****************************************************************************/
void QuickSort(struct Person pArr[], int sortBy)
{
	switch(sortBy)
	{
		case 1: qsort(pArr, ROW_SIZE, sizeof(struct Person), CompareByName);
				break;

		case 2: qsort(pArr, ROW_SIZE, sizeof(struct Person), CompareByAge);
				break;

		case 3: qsort(pArr, ROW_SIZE, sizeof(struct Person), CompareByFruit);
				break;
	}
}


/*
 * F1_MergeSort.c
 *
 *  Created on: Feb 26, 2021
 *      Author: ctqdt
 */
#include "header.h"

void BubbleSort(struct Person pArr[5], int sortBy)
{
	struct Person temp;
	int size = 5;

	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - 1 - i; j++)
		{
			switch(sortBy)
			{
				case 1:	if(strcmp(pArr[j].name, pArr[j+1].name) > 0)
						{
							temp = pArr[j];
							pArr[j] = pArr[j+1];
							pArr[j+1] = temp;
						}
						break;

				case 2:	if(pArr[j].age > pArr[j+1].age)
						{
							temp = pArr[j];
							pArr[j] = pArr[j+1];
							pArr[j+1] = temp;
						}
						break;

				case 3:	if(strcmp(pArr[j].fruit,pArr[j+1].fruit) > 0)
						{
							temp = pArr[j];
							pArr[j] = pArr[j+1];
							pArr[j+1] = temp;
						}
						break;
				default:	printf("Error - List not sorted!");
			}
		}
	}
}




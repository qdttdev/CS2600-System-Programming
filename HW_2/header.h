/*
 * header.h
 *
 *  Created on: Feb 26, 2021
 *      Author: ctqdt
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <stdio.h>		// standard I/O functions
#include <stdbool.h>	// boolean
#include <string.h>		// strcmp
#include <stdlib.h>		// malloc

struct Person
{
	char	name[100];
	int		age;
	char	fruit[100];
};

// Function Declaration
void BubbleSort(struct Person pArr[5], int sortBy);
void ReadInput (FILE *fin, struct Person pArr[]);
void PrintData(struct Person pArr[]);

#endif /* HEADER_H_ */

#include "header.h"

void PrintData(struct Person pArr[])
{
	for(int i = 0; i < 5; i++)
	{
		printf("\n%s, %d, %s",pArr[i].name, pArr[i].age, pArr[i].fruit);
	}
}



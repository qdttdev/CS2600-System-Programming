#include "header.h"

void ReadInput (FILE *fin, struct Person pArr[])
{
	size_t lineBuffSize = 100;
	char* lineBuff = malloc(lineBuffSize);
	int i = 0;

	while(getline(&lineBuff, &lineBuffSize, fin) != -1)
	{
//		printf("Reading in: %s", lineBuff);

		char* token;
		char* element;

		token = strtok(lineBuff,", \n");

		element = token;
		strcpy(pArr[i].name, element);
		token = strtok (NULL, ", \n");

		element = token;
		pArr[i].age = atoi(element);
		token = strtok (NULL, ", \n");

		element = token;
		token = strtok (NULL, ", \n");
		strcpy(pArr[i].fruit, element);

		i++;
	}

	// Free the allocated line buffer
	free(lineBuff);
	lineBuff = NULL;
}



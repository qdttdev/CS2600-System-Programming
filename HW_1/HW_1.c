/*******************************************************************************
 * Name:	Caroline Ta
 * Date:	02/03/2021
 * Class:	CS2600.02
 * HW:		Homework 1 - Nim (Extra Credit #1)
 ******************************************************************************/

#include <stdio.h>		// standard input/output functions
#include <stdlib.h>		// rand
#include <time.h>		// time
#include <stdbool.h>	// boolean

void playGame(int *count, int *max, int pileID)
{
	int userInput = 0;
	int pcInput = 0;
	bool validInput;

	if(count[pileID] > 1)
	{
		// 3. Determine the largest value the user can take: 1/2 of count
		max[pileID] = count[pileID]/2;

		// 4. Prompt the user to enter a value between 1 and the max value in #3
		do
		{
			printf("User input (1-%d): ", max[pileID]);
			scanf("%d", &userInput);
			validInput = userInput >= 1 && userInput <= max[pileID];

			// 5. Error check for user's input
			if(!validInput)
			{
				printf("Invalid user input, please try again\n");
			}
		}
		while(!validInput);

		// 6. Subtract the value from count
		count[pileID] -= userInput;
		max[pileID] = count[pileID]/2;
		printf("MARBLES COUNT PILE #%d: %d", pileID+1, count[pileID]);

		if(count[pileID] == 1)
		{
			printf("\n\n***** Computer takes the last marble - User Wins! *****\n");
		}
		else
		{
			// 7. Determine the number of marbles to be taken by the program.
			pcInput = rand() % max[pileID] + 1;
			printf("\nComputer input (1-%d): %d", max[pileID], pcInput);
			count[pileID] -= pcInput;
			printf("\nMARBLES COUNT PILE #%d: %d", pileID+1, count[pileID]);

			if(count[pileID] == 1)
			{
				printf("\n\n***** User takes the last marble - Computer Wins! *****\n");
			}
		}
	}
	else
	{
		printf("Game Finished\n");
	}
}

int main(void)
{
	// VARIABLES
	int count[3] = {0};
	int max[3] = {0};
	int userInput = 0;
	bool validInput;

	// Clear the buffer
	setbuf(stdout, NULL);
	// Set seed to generate different a number every time the program runs
	srand(time(NULL));

	// 1. Generate a random number from 10-100
	count[0] = rand() % 91 + 10;
	count[1] = rand() % 91 + 10;
	count[2] = rand() % 91 + 10;

	// 2. Inform the player of the number of marbles, count
	printf("MARBLES COUNT PILE #1: %d\n", count[0]);
	printf("MARBLES COUNT PILE #2: %d\n", count[1]);
	printf("MARBLES COUNT PILE #3: %d\n", count[2]);

	// 8. Go back to step 2, unless either the program or the user wins
	while(count[0] > 1 || count[1] > 1 || count[2] > 1)
	{
		do
		{
			printf("\n\nWhich pile do you want to take from? (1-3): ");
			scanf("%d", &userInput);
			validInput = userInput >= 1 && userInput <= 3;

			// 5. Error check for user's input
			if(!validInput)
			{
				printf("Invalid input, please try again\n");
			}
		}
		while(!validInput);

		switch(userInput)
		{
			case 1:	playGame(count, max, userInput-1);
			break;

			case 2:	playGame(count, max, userInput-1);
			break;

			case 3:	playGame(count, max, userInput-1);
			break;
		}
	}

	return 0;
}

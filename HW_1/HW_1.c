/*******************************************************************************
 * Name:	Caroline Ta
 * Date:	02/03/2021
 * Class:	CS2600.02
 * HW:		Homework 1 - Nim
 ******************************************************************************/

#include <stdio.h>		// standard input/output functions
#include <stdlib.h>		// rand
#include <time.h>		// time
#include <stdbool.h>	// boolean

int main(void)
{
	// VARIABLES
	int count = 0;
	int max = 0;
	int userInput = 0;
	int pcInput = 0;
	bool validInput;

	// Clear the buffer
	setbuf(stdout, NULL);
	// Set seed to generate different a number every time the program runs
	srand(time(0));
	// 1. Generate a random number from 10-100
	count = rand() % 91 + 10;

	// 2. Inform the player of the number of marbles, count
	printf("MARBLES COUNT: %d\n", count);

	// 8. Go back to step 2, unless either the program or the user wins
	while(count > 1)
	{
		// 3. Determine the largest value the user can take: 1/2 of count
		max = count/2;

		// 4. Prompt the user to enter a value between 1 and the max value in #3
		do
		{
			printf("User input (1-%d): ", max);
			scanf("%d", &userInput);
			validInput = userInput >= 1 && userInput <= max;

			// 5. Error check for user's input
			if(!validInput)
			{
				printf("Invalid user input, please try again\n");
			}
		}
		while(!validInput);

		// 6. Subtract the value from count
		count -= userInput;
		max = count/2;
		printf("\nMARBLES COUNT: %d\n", count);

		if(count == 1)
		{
			printf("\n***** Computer takes the last marble - User Wins! *****\n");
			break;
		}

		// 7. Determine the number of marbles to be taken by the program.
		pcInput = rand() % max + 1;
		printf("Computer input (1-%d): %d\n\n", max, pcInput);
		count -= pcInput;
		printf("\nMARBLES COUNT: %d\n", count);

		if(count == 1)
		{
			printf("\n***** User takes the last marble - Computer Wins! *****\n");
		}
	}

	return 0;
}

#include <stdio.h>
#include <string.h>

int NumberOfLives = 3;

struct CorrectAnswer
{
	char name[20];
	int isGuessed;
};

struct CorrectAnswer CorrectAnswers[3];

int IsCorrectAnswer(char answer[])
{
	int counter;

	for (counter = 0; counter < 3; ++counter)
	{
		if (strcmp(CorrectAnswers[counter].name, answer) == 0)
		{
			CorrectAnswers[counter].isGuessed = 1;
			return 1;
		}
	}

	return 0;
}

int isAllAnswered()
{
	int counter;

	for (counter = 0; counter < 3; ++counter)
	{
		if (CorrectAnswers[counter].isGuessed == 0)
		{
			return 0;
		}
	}

	return 1;
}


int main(void)
{
	strncpy_s(CorrectAnswers[0].name, 20, "greek", 5);
	strncpy_s(CorrectAnswers[1].name, 20, "week", 4);
	strncpy_s(CorrectAnswers[2].name, 20, "meek", 4);

	printf("Let's play Family Fortunes!");
	printf("\nHere is your question, there are 3 possible answers");
	printf("\nYou have %d lives to guess them all", NumberOfLives);
	printf("\n\nName a word ending in 'eek'");



	while (NumberOfLives > 0 && isAllAnswered() == 0)
	{

		printf("\nEnter your answer: ");
		char givenAnswer[20];
		fgets(givenAnswer, 20, stdin);

		//trim
		char trimedAnswer[20];
		int len = strcspn(givenAnswer, "\n");
		strncpy_s(trimedAnswer, 20, givenAnswer, len);

		if (IsCorrectAnswer(trimedAnswer) > 0)
		{
			printf("\nYes, it's on the board! Well Done!");
		}
		else
		{
			printf("\nSorry, nobody said that");
			NumberOfLives--;
		}

		printf("\nYou have %d lives remaining\n", NumberOfLives);

	}

	if (isAllAnswered() > 0)
	{
		printf("\nFinal Result: Well done, you have baet the board!");
	}
	else
	{
		printf("\nFinal Result: You have run out of lives :(");
	}
}
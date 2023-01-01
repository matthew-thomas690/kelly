#include <stdio.h>
#include <math.h>

double SquareLength;
double CircleRadius;
double Pi = 3.142;

void collectInputs()
{
	int isInputValid = 0;

	while (isInputValid == 0)
	{
		printf("Enter the Radius of the Cicle : ");
		scanf_s("%lf", &CircleRadius);
		printf("Enter the Length of the Square : ");
		scanf_s("%lf", &SquareLength);
		isInputValid = checkInputsAreValid();
		if (isInputValid == 0)
		{
			printf("The Square exceed the dimensions of the Circle. Try Again.\n\n");
		}
	}
}

int checkInputsAreValid()
{
	if (CircleRadius > SquareLength * sqrt(2))
	{
		return 1;
	}

	return 0;
}

double calculateArea()
{
	double circleArea = Pi * (CircleRadius * CircleRadius);
	double squareArea = SquareLength * SquareLength;

	return circleArea - squareArea;
}

void outputResult(float result)
{
	printf("\n\nresult : %lf", result);
}

int main(void)
{
	collectInputs();
	double result = calculateArea();
	outputResult(result);
}

#include <stdio.h>
#include <string.h>

struct ShoppingListItem 
{
	float price;
	char name[50];
	int isInitialized;
};

char poundSymbol = 156;
struct ShoppingListItem ShoppingList[50];

void collectInputs()
{
	int counter;

	for (counter = 0; counter < 50; ++counter)
	{
		float price;
		char name[51];

		printf("Please enter the name of the next item or type 'exit' to finish your list: ");
		fgets(name, 50, stdin);

		if (strcmp("exit\n", name) == 0)
		{
			break;
		}
		printf("Please enter the price of item in %c: ", poundSymbol);
		scanf_s("%f", &price);
		int len = strcspn(name, "\n");
		strncpy_s(ShoppingList[counter].name, 50, name, len);
		ShoppingList[counter].price = price;
		ShoppingList[counter].isInitialized = 1;
		getchar(); // removes newline char from buffer
	}
}

void outputShoppingList()
{
	

	printf("\nHere is a list of your shopping:");

	int counter;
	float total = 0;

	for (counter = 0; counter < 50; ++counter)
	{
		if (ShoppingList[counter].isInitialized != 1)
		{
			break;
		}
		total += ShoppingList[counter].price;
		printf("\n%s %c%0.2f", ShoppingList[counter].name, poundSymbol, ShoppingList[counter].price);
	}

	printf("\n\nYour shopping costs %c%0.2f overall", poundSymbol, total);
	printf("\n\nDrawing a raffle ticket...");
	int discountPercentage = getDiscount();

	float discountValue = total / 100 * discountPercentage;
	total -= discountValue;

	printf("\nYour discount is %d %% !", discountPercentage);
	printf("\n\nYour new shopping total is %c%0.2f\n\n", poundSymbol, total);
}

int getDiscount()
{
	return (rand() % (40 - 10 + 1)) + 10;
}

int main(void)
{
	collectInputs();
	outputShoppingList();
}
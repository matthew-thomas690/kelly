#include <stdio.h>

char Name[50];
char NIN[12];
int Age;
float Pay;

int main(void)
{
	//collect inputs
	printf("Enter Your Name : ");
	fgets(Name, 50, stdin);
	printf("Enter Your National Insurance Number : ");
	fgets(NIN, 12, stdin);
	printf("Enter Your Age : ");
	scanf_s("%d", &Age);
	printf("Enter Your Current Take-home Pay : ");
	scanf_s("%f", &Pay);
	
	// output at end
	printf("\nName : %s", Name);
	printf("National Insurance Number : %s", NIN);
	printf("Age : %d", Age);
	printf("\nPay : %0.2f", Pay);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n1 = 0, n2 = 1, sum = 0, n;

	printf("Enter any positive number: ");
	scanf("%d", &n);

	printf("Fibonacci Squence: %d, %d, ", n1, n2);
  
	sum = n1 + n2;
	
  while (sum <= n)
	{
		printf("%d, ", sum);
		n1 = n2;
		n2 = sum;
		sum = n1 + n2;
	}

	printf("\n");

	system("pause");
	return 0;
}

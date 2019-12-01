#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Matrix Calculator\n");
	
	printf("Enter Values for Matrix A:\n");
	
	int matrixA[2][2];

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			scanf("%d", &matrixA[i][j]);


	printf("Enter Values for Matrix B:\n");

	int matrixB[2][2];

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			scanf("%d", &matrixB[i][j]);

	printf("\n");
	printf("Addition\n");
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
			printf("%d\t", matrixA[i][j] + matrixB[i][j]);
		printf("\n");
	}

	printf("Substraction\n");
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
			printf("%d\t", matrixA[i][j] - matrixB[i][j]);
		printf("\n");
	}

	int result[2][2];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < 2; k++)
				result[i][j] += matrixA[i][k] * matrixB[k][j];
		}

	printf("Multiplication\n");
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
			printf("%d\t", result[i][j]);
		printf("\n");
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < 2; k++)
				result[i][j] += matrixA[i][k] / matrixB[k][j];
		}
	}

	printf("Division\n");
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
			printf("%d\t", result[i][j]);
		printf("\n");
	}

	system("pause>nil");
	return 0;
}

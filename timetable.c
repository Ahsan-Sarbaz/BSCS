#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	while (1)
	{
		system("CLS");
		printf("\tTime Table\n");
		printf("\nOptions: \n 1. Monday\n 2. Tuesday\n 3. Wednesday\n 4. Thursday\n 5. Friday\n 6. Saturday\n 7. Sunday\n 0. Exit\n");
		char choice = 0;
		scanf(" %c", &choice);
		switch (choice)
		{
		case '1':
			printf("\nICT\n\n");
			break;
		case '2':
			printf("\nIntroduction To Programming\n\n");
			break;
		case '3':
			printf("\nPhysics\n\n");
			break;
		case '4':
			printf("\nEnglish\n\n");
			break;
		case '5':
			printf("\nCalculas\n\n");
			break;
		case '6':
			printf("\nOFF\n\n");
			break;
		case '7':
			printf("\nOFF\n\n");
			break;
		case '0':
			return 0;
			break;
		default:
			printf("\nInvalid Choice!\n\n");
			system("PAUSE");
			break;
		}
		system("PAUSE");
	}
	return 0;
}

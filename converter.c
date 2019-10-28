#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
	
int main()
{
	while (1)
	{
		system("CLS");

		printf("Enter Volume : ");
		float volume;
		scanf("%f", &volume);
		printf("\n1. Gallons\n2. Liters\n");
		int choice;
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("%.2f Gallons is equal to %.2f Liters\n", volume,  volume / 3.785f);
		}else if (choice == 2)
		{
			printf("%.2f Liters is equal to %.2f Gallons\n", volume, volume * 3.785f);
		}

		system("PAUSE");
	}
	return 0;
}

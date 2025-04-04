#include <stdio.h>
#define Maxsize 50
//Naphatsorn wattanon 6621600321 sec700
void main()
{
	int i, j, k, Row_3D, Column_3D, Depth_3D;
	float array_3DPoint[Maxsize][Maxsize][Maxsize];
	float *p;
	float sum;
	char answer;

	do
	{
		do
		{
			printf("Please enter size of array 3D (Depth): ");
			scanf(" %d", &Depth_3D);
			if (Depth_3D < 2 || Depth_3D > Maxsize)
			{
				printf("error depth and the maximum size is 50\n");
			}
		} while (Depth_3D < 2 || Depth_3D > Maxsize);

		printf("\n");

		do
		{
			printf("Please enter size of array 3D (rows): ");
			scanf(" %d", &Row_3D);
			if (Row_3D < 2 || Row_3D > Maxsize)
			{
				printf("error rows and the maximum size is 50\n");
			}
		}while(Row_3D < 2 || Row_3D > Maxsize);
			printf("\n");

		do
		{
			printf("Please enter size of array 3D (columns): ");
			scanf(" %d", &Column_3D);
			if (Column_3D < 1 || Column_3D > Maxsize)
			{
				printf("error column and the maximum size is 50\n");
			}
		} while (Column_3D < 1 || Column_3D > Maxsize);

		printf("\n");

		printf("Enter values for array_3D:\n");
		for (k = 0; k < Depth_3D; k++)
		{
			printf("Layer %d:\n", k);
			for (i = 0; i < Row_3D; i++)
			{
				for (j = 0; j < Column_3D; j++)
				{
					printf("Enter value for position [%d][%d][%d]: ", k, i, j);
					scanf("%f", &array_3DPoint[k][i][j]);
				}
			}
		}

		sum = 0;

		p = &array_3DPoint[0][0][0];

		for (k = 0; k < Depth_3D; k++)
		{
			for (i = 0; i < Row_3D; i++)
			{
				for (j = 0; j < Column_3D; j++)
				{
					sum += *(p + (k * Maxsize * Maxsize) + (i * Maxsize) + j);
				}
			}
		}


		printf("Sum of array 3D by Pointer is %.2f\n", sum);

		printf("Do you want to do it again? (y/n): ");
		scanf(" %c", &answer);
	} while (answer == 'y' || answer == 'Y');
}

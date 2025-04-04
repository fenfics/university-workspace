#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Maxsize 30

void main()
{
	int array_3D[Maxsize][Maxsize][Maxsize];
	int Row_3D, Column_3D, Depth_3D, Array3D_size, temp;
	char answer;
	int i, j, k, x, y, z;

	do
	{

		srand(time(NULL));
		do
		{
			printf("Please enter size of array 3D (Depth): ");
			scanf(" %d", &Depth_3D);
			if (Depth_3D < 2 || Depth_3D > Maxsize)
			{
				printf("error depth and the maximum size is 30\n");
			}
		} while (Depth_3D < 2 || Depth_3D > Maxsize);
		printf("\n");

		do
		{
			printf("Please enter size of array 3D (rows): ");
			scanf(" %d", &Row_3D);
			if (Row_3D < 2 || Row_3D > Maxsize)
			{
				printf("error rows and the maximum size is 30\n");
			}
		} while (Row_3D < 2 || Row_3D > Maxsize);
		printf("\n");

		do
		{
			printf("Please enter size of array 3D (columns): ");
			scanf(" %d", &Column_3D);
			if (Column_3D < 1 || Column_3D > Maxsize)
			{
				printf("error column and the maximum size is 30\n");
			}
		} while (Column_3D < 1 || Column_3D > Maxsize);
		printf("\n");

		printf("\n");

		for (k = 0; k < Depth_3D; k++)
		{
			for (i = 0; i < Row_3D; i++)
			{
				for (j = 0; j < Column_3D; j++)
				{
					array_3D[k][i][j] = rand() % 1201;
				}
			}
		}

		printf("Value of Array_3D before sorting:\n");
		for (k = 0; k < Depth_3D; k++)
		{
			printf("Layer %d:\n", k);
			for (i = 0; i < Row_3D; i++)
			{
				for (j = 0; j < Column_3D; j++)
				{
					printf("%d\t", array_3D[k][i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}

		for (k = 0; k < Depth_3D; k++)
		{
			for (i = 0; i < Row_3D; i++)
			{
				for (j = 0; j < Column_3D; j++)
				{
					for (x = 0; x < Depth_3D; x++)
					{
						for (y = 0; y < Row_3D; y++)
						{
							for (z = 0; z < Column_3D; z++)
							{
								if (array_3D[k][i][j] < array_3D[x][y][z])
								{
									temp = array_3D[k][i][j];
									array_3D[k][i][j] = array_3D[x][y][z];
									array_3D[x][y][z] = temp;
								}
							}
						}
					}
				}
			}
		}

		printf("Value of Array_3D after sorting:\n");
		for (k = 0; k < Depth_3D; k++)
		{
			printf("Layer %d:\n", k);
			for (i = 0; i < Row_3D; i++)
			{
				for (j = 0; j < Column_3D; j++)
				{
					printf("%d\t", array_3D[k][i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}

		printf("Do you want to do it again? (y/n): ");
		scanf(" %c", &answer);
	} while (answer == 'y' || answer == 'Y');
}

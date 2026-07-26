#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Maxsize 30
//FN-random Array3D
void show_array_3D(int depth, int row, int column,int array_3D[Maxsize][Maxsize][Maxsize]);
void Randoms_Array3D(int depth, int row, int column, int array_3D[Maxsize][Maxsize][Maxsize]);
void Sort_Array3D(int depth, int row, int column, int array_3D[Maxsize][Maxsize][Maxsize]);
int k, i, j, temp, x, y, z;

void main()
{
    int Row_3D, Column_3D, Depth_3D;
    char answer;
    int array_3D[Maxsize][Maxsize][Maxsize];

    do
    {
		do{
        printf("Please enter size of array 3D (Depth): ");
        scanf(" %d", &Depth_3D);
        if (Depth_3D < 2 || Depth_3D > Maxsize)
        {
            printf("!!!error depth and the maximum size is 30 !!!\n");
        }
		}while(Depth_3D < 2 || Depth_3D > Maxsize);
        printf("\n");

		do{
        printf("Please enter size of array 3D (rows): ");
        scanf(" %d", &Row_3D);
        if (Row_3D < 2 || Row_3D > Maxsize)
        {
            printf("!!!error rows and the maximum size is 30 !!!\n");
        }
		}while(Row_3D < 2 || Row_3D > Maxsize);
        printf("\n");

		do{
        printf("Please enter size of array 3D (columns): ");
        scanf(" %d", &Column_3D);
        if (Column_3D < 1 || Column_3D > Maxsize)
        {
            printf("!!!error column and the maximum size is 30 !!!\n");
        }
		}while(Column_3D < 1 || Column_3D > Maxsize);

        printf("\n");

        printf("\n");

        Randoms_Array3D(Depth_3D, Row_3D, Column_3D, array_3D);

        printf("Value of Array_3D before sorting:\n");
        show_array_3D(Depth_3D, Row_3D, Column_3D, array_3D);
        printf("\n");

        Sort_Array3D(Depth_3D, Row_3D, Column_3D, array_3D);

        printf("Value of Array_3D after sorting:\n");
        show_array_3D(Depth_3D, Row_3D, Column_3D, array_3D);
        printf("\n");

        printf("Do you want to do it again? (y/n): ");
        scanf(" %c", &answer);
    } while (answer == 'y' || answer == 'Y');
}


void Randoms_Array3D(int depth, int row, int column, int array_3D[Maxsize][Maxsize][Maxsize])
{
    srand(time(NULL));
    for (k = 0; k < depth; k++)
    {
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < column; j++)
            {
                array_3D[k][i][j] = rand() % 1201;
            }
        }
    }
}

void show_array_3D(int depth, int row, int column,int array_3D[Maxsize][Maxsize][Maxsize])
{
    for (k = 0; k < depth; k++)
    {
        printf("Layer %d:\n", k);
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < column; j++)
            {
                printf("%d\t", array_3D[k][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void Sort_Array3D(int depth, int row, int column, int array_3D[Maxsize][Maxsize][Maxsize])
{
    for (k = 0 ; k < depth; k++)
        {
            for (i = 0 ; i < row; i++)
            {
                for (j = 0 ; j < column; j++)
                {
                    for (x = 0 ; x < depth; x++)
                    {
                        for (y = 0 ; y < row; y++)
                        {
                            for (z = 0 ; z < column; z++)
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
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Maxsize 30

void main()
{
    int array_3D[Maxsize][Maxsize][Maxsize];
    int Row_3D, Column_3D, Depth_3D, Array3D_size;
    char answer;
    int i, j, k, *pointer, max_value, min_value, current_value;
    int max_pos_k, max_pos_i, max_pos_j, min_pos_k, min_pos_i, min_pos_j;

    do
    {
        do
        {
            printf("Please enter size of array 3D (Depth): ");
            scanf(" %d", &Depth_3D);
            if (Depth_3D < 2 || Depth_3D > Maxsize)
            {
                printf("error depth and the maximum size is 30\n");
            }
        } while (Depth_3D < 2 || Depth_3D > Maxsize);

        do
        {
            printf("Please enter size of array 3D (rows): ");
            scanf(" %d", &Row_3D);
            if (Row_3D < 2 || Row_3D > Maxsize)
            {
                printf("error rows and the maximum size is 30\n");
            }
        } while (Row_3D < 2 || Row_3D > Maxsize);

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

        srand(time(NULL));
        for (k = 0; k < Depth_3D; k++)
        {
            for (i = 0; i < Row_3D; i++)
            {
                for (j = 0; j < Column_3D; j++)
                {
                    array_3D[k][i][j] = rand() % 501;
                }
            }
        }

        printf("Value of Array_3D:\n");
        for (k = 0; k < Depth_3D; k++)
        {
            printf("Layer %d:\n", k);
            for (i = 0; i < Row_3D; i++)
            {
                for (j = 0; j < Column_3D; j++)
                {
                    printf("%d [%d][%d][%d]\t", array_3D[k][i][j], k, i, j);
                }
                printf("\n");
            }
            printf("\n");
        }


		pointer = &array_3D[0][0][0];
		max_value = *pointer;
		min_value = *pointer;

        max_pos_k = 0, max_pos_i = 0, max_pos_j = 0, min_pos_k = 0, min_pos_i = 0, min_pos_j = 0;

        for (k = 0; k < Depth_3D; k++)
        {
            for (i = 0; i < Row_3D; i++)
            {
                for (j = 0; j < Column_3D; j++)
                {
                    current_value = *(pointer + (k * Row_3D * Column_3D) + (i * Column_3D) + j);
                    if (current_value > max_value)
                    {
                        max_value = current_value;
                        max_pos_k = k;
                        max_pos_i = i;
                        max_pos_j = j;
                    }
                    if (current_value < min_value)
                    {
                        min_value = current_value;
                        min_pos_k = k;
                        min_pos_i = i;
                        min_pos_j = j;
                    }
                }
            }
        }

        printf("Maximum value is %d at [%d][%d][%d]\n", max_value, max_pos_k, max_pos_i, max_pos_j);
        printf("Minimum value is %d at [%d][%d][%d]\n", min_value, min_pos_k, min_pos_i, min_pos_j);

        printf("Do you want to do it again? (y/n): ");
        scanf(" %c", &answer);
        printf("-----------------------------------------------------\n");

    } while (answer == 'y' || answer == 'Y');
}

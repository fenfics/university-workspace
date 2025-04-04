#include <stdio.h>
#define Maxsize 30

void show_array2D(int Row_2D, int Column_2D, float array_2D[Maxsize][Maxsize]);
void show_array3D(int Depth_3D, int Row_3D, int Column_3D, float array_3D[Maxsize][Maxsize][Maxsize]);
void set_array2D(int Row_2D, int Column_2D, float array_2D[Maxsize][Maxsize]);
void set_array3D(int Depth_3D, int Row_3D, int Column_3D, float array_3D[Maxsize][Maxsize][Maxsize]);
float array_2D[Maxsize][Maxsize], array_3D[Maxsize][Maxsize][Maxsize];
int i, j, k, Row_2D, Column_2D, Row_3D, Column_3D, Depth_3D;

void main()
{
    char answer;
    do
    {
        do
        {
            printf("Please enter size of array 2D (rows): ");
            scanf(" %d", &Row_2D);
            if (Row_2D < 2 || Row_2D > Maxsize)
            {
                printf("error rows and the maximum size is 30\n");
            }
        } while (Row_2D < 2 || Row_2D > Maxsize);
        printf("\n");

        do
        {
            printf("Please enter size of array 2D (columns): ");
            scanf(" %d", &Column_2D);
            if (Column_2D < 1 || Column_2D > Maxsize)
            {
                printf("error column and the maximum size is 30\n");
            }
        } while (Column_2D < 1 || Column_2D > Maxsize);
        printf("\n");

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

        set_array2D(Row_2D, Column_2D, array_2D);
        set_array3D(Depth_3D, Row_3D, Column_3D, array_3D);

        show_array2D(Row_2D, Column_2D, array_2D);
        show_array3D(Depth_3D, Row_3D, Column_3D, array_3D);

        printf("Do you want to do it again? (y/n): ");
        scanf(" %c", &answer);
    } while (answer == 'y' || answer == 'Y');
}

void show_array2D(int Row_2D, int Column_2D, float array_2D[Maxsize][Maxsize])
{

    printf("\nValue of array_2D\n");
    for (i = 0; i < Row_2D; i++)
    {
        for (j = 0; j < Column_2D; j++)
        {
            printf("%.2f\t", array_2D[i][j]);
        }
        printf("\n");
    }
}

void show_array3D(int Depth_3D, int Row_3D, int Column_3D, float array_3D[Maxsize][Maxsize][Maxsize])
{
    printf("\nValue of array_3D\n");
    for (k = 0; k < Depth_3D; k++)
    {
        printf("Layer %d:\n", k);
        for (i = 0; i < Row_3D; i++)
        {
            for (j = 0; j < Column_3D; j++)
            {
                printf("%.2f\t", array_3D[k][i][j]);
            }
            printf("\n");
        }
    }
}

void set_array2D(int Row_2D, int Column_2D,float array_2D[Maxsize][Maxsize])
{
    printf("Enter value for array_2D\n");
    for (i = 0; i < Row_2D; i++)
    {
        for (j = 0; j < Column_2D; j++)
        {
            array_2D[i][j] = 0;
            printf("Enter value for position [%d][%d]: ", i, j);
            scanf(" %f", &array_2D[i][j]);
        }
    }

    printf("\n");
}

void set_array3D(int Depth_3D, int Row_3D, int Column_3D, float array_3D[Maxsize][Maxsize][Maxsize])
{
    printf("Enter value for array_3D\n");
    for (k = 0; k < Depth_3D; k++)
    {
        printf("Layer %d:\n", k);
        for (i = 0; i < Row_3D; i++)
        {
            for (j = 0; j < Column_3D; j++)
            {
                array_3D[k][i][j] = 0;
                printf("Enter value for position [%d][%d][%d]: ", k, i, j);
                scanf(" %f", &array_3D[k][i][j]);
            }
        }
        printf("\n");
    }
}

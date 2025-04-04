#include <stdio.h>
#define Maxsize 100

void main()
{
    float array_A[Maxsize][Maxsize], array_B[Maxsize][Maxsize], array_C[Maxsize][Maxsize];
    int i, j, n, m;
    float avrs, sum;
    char answer;

    do
    {
        sum = 0;
        do{
        printf("Please enter size of array (rows): ");
        scanf(" %d", &m);
        if(m < 2 || m > Maxsize)
        	{
            	printf("error rows and the sizes are between 2-100\n");
        	}
		}while(m < 2 || m > Maxsize);

		do{
        printf("Please enter size of array (columns): ");
        scanf(" %d", &n);
        if(n < 1 || n > Maxsize)
        	{
            	printf("error column and the sizes are between 1-100\n");
        	}
		}while(n < 1 || n > Maxsize);

        printf("Enter value for array_A\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                array_A[i][j] = 0;
                printf("Enter value for position [%d][%d]: ", i, j);
                scanf(" %f", &array_A[i][j]);
            }
        }

        printf("\nEnter value for array_B\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                array_B[i][j] = 0;
                printf("Enter value for position [%d][%d]: ", i, j);
                scanf(" %f", &array_B[i][j]);
            }
        }

        printf("\nValue of array_A\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf(" %.2f\t", array_A[i][j]);
            }
            printf("\n");
        }

        printf("\nValue of array_B\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf(" %.2f\t", array_B[i][j]);
            }
            printf("\n");
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                array_C[i][j] = array_A[i][j] * array_B[i][j];
            }
        }

        printf("\nValue of array_C\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf(" %.2f\t", array_C[i][j]);
            }
            printf("\n");
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                sum += array_C[i][j];
            }
        }

        avrs = sum / (n * m);
        printf("\nAverage of array is %.2f\n", avrs);
        printf("\n");

        printf("Do you want to do it again? (y/n): ");
        scanf(" %c", &answer);

    } while (answer == 'y' || answer == 'Y');
}

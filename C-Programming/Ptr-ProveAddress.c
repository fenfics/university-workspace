#include <stdio.h>

void main()
{
    int *p_1D, *p_2D, *p_3D;
    int i, j, k;

    int array_1D[5] = {1, 2, 3, 4, 5};
    int array_2D[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array_3D[2][3][3] = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},{{10, 11, 12}, {13, 14, 15}, {16, 17, 18}}};

    p_1D = &array_1D[0];
    p_2D = &array_2D[0][0];
    p_3D = &array_3D[0][0][0];
    printf("Value of Array 1D size 5 and Address\n");
    for (i = 0; i < 5; i++)
    {
        printf("array_1D[%d] address is %u, Value from pointer is %d\n", i, (p_1D+i), *(p_1D+i));
    }
    printf("\n");
    printf("Value of Array 2D size 3*3 and Address\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("array_2D[%d][%d] address is %u, Value from pointer is %d\n", i, j, (p_2D+i*3+j), *(p_2D+i*3+j));
        }
        printf("\n");
    }
    printf("\n");
    printf("Value of Array 3D size 2*3*3 and Address\n");
    for (i = 0; i < 2; i++)
    {
		printf("Layer %d \n",i);
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                printf("array_3D[%d][%d][%d] address is %u, Value from pointer is %d\n", i, j, k, (p_3D + i * 3 * 3 + j * 3 + k), *(p_3D + i * 3 * 3 + j * 3 + k));
            }
        }
        printf("\n");
    }
    printf("\n");
}

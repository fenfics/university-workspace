#include <stdio.h>
#define Maxsize 50

void setArray(int column, int array[Maxsize]);
void ShowArray(int column, int array[Maxsize]);
void swapArray(int *pos_first, int *pos_second, int pos1, int pos2);
int i;

void main()
{
    int array_first[Maxsize], array_second[Maxsize];
    int size, pos_array_first, pos_array_second;
    char answer;
    do
    {
        do {
            printf("Please Enter size of array: ");
            scanf(" %d", &size);

            if (size < 2 || size > Maxsize) {
                printf("error size and the sizes are between 2-50\n");
            }
        } while (size < 2 || size > Maxsize);

        printf("Set values for array_first\n");
        setArray(size, array_first);
        printf("\n");

        printf("Set values for array_second\n");
        setArray(size, array_second);
        printf("\n");

        printf("Values of array_first\n");
        ShowArray(size, array_first);
        printf("\n");

        printf("Values of array_second\n");
        ShowArray(size, array_second);
        printf("\n");

        do
        {
            do {
                printf("Which position to swap in array_first(i.e. 0,1,2): ");
                scanf(" %d", &pos_array_first);
                if (pos_array_first < 0 || pos_array_first >= size) {
                    printf("error position \n");
                }
            } while (pos_array_first < 0 || pos_array_first >= size);

            do {
                printf("Which position to swap in array_second(i.e. 0,1,2): ");
                scanf(" %d", &pos_array_second);
                if (pos_array_second < 0 || pos_array_second >= size) {
                    printf("error position \n");
                }
            } while (pos_array_second < 0 || pos_array_second >= size);

            swapArray(&array_first[pos_array_first], &array_second[pos_array_second], pos_array_first, pos_array_second);

            printf("\n");
            printf("After swapping:\n");

            printf("Values of array_first\n");
            ShowArray(size, array_first);
            printf("\n");

            printf("Values of array_second\n");
            ShowArray(size, array_second);
            printf("\n");

            printf("Do you want to swap again? (y/n): ");
            scanf(" %c", &answer);

        } while (answer == 'y' || answer == 'Y');

        printf("Do you want to set new array? (y/n): ");
        scanf(" %c", &answer);

    } while (answer == 'y' || answer == 'Y');
}

void setArray(int column, int array[Maxsize])
{
    for (i = 0; i < column; i++)
    {
        array[i] = 0;
        printf("Enter value for position [%d]: ", i);
        scanf(" %d", &array[i]);
    }
}

void ShowArray(int column, int array[Maxsize])
{
    for (i = 0; i < column; i++)
    {
        printf("position[%d] value is %d and Address is %u \n", i, array[i], &array[i]);
    }
    printf("\n");
}

void swapArray(int *pos_first, int *pos_second, int pos1, int pos2)
{
    int temp = *pos_first;
    *pos_first = *pos_second;
    *pos_second = temp;
    printf("----------------------------------------\n");
    printf("Swapped values at positions %d and %d\n", pos1, pos2);
}

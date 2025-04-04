#include <stdio.h>
#define Maxsize 30
//Naphatsorn wattanon 6621600321 sec700
void set_valueOfArray(int size, int array[Maxsize]);
void ShowArray(int size, int array[Maxsize]);
void calArray(int size, int array_1[Maxsize], int array_2[Maxsize], int array_3[Maxsize]);
int array_1[Maxsize], array_2[Maxsize], array_3[Maxsize];
int i, size;

void main()
{
    char answer;
    do
    {
        do
        {
            printf("Please enter size of array: ");
            scanf("%d", &size);
            if(size < 2 || size > Maxsize){
				printf("!!!error size and the size is between 2 - 30\n");
			}
        } while (size < 2 || size > Maxsize);

        printf("Set value of array_1\n");
        set_valueOfArray(size, array_1);

        printf("Set value of array_2\n");
        set_valueOfArray(size, array_2);

        calArray(size, array_1, array_2, array_3);

        printf("value of array_1\n");
        ShowArray(size, array_1);
        printf("\n");

        printf("value of array_2\n");
        ShowArray(size, array_2);
        printf("\n");

        printf("value of array_3\n");
        ShowArray(size, array_3);
        printf("\n");


        printf("Do you want to do it again? (y/n): ");
        scanf(" %c", &answer);

    } while (answer == 'y' || answer == 'Y');
}

void set_valueOfArray(int size, int array[Maxsize])
{

    for (i = 0; i < size; i++)
    {
        printf("Enter value for position [%d]: ", i);
        scanf("%d", &array[i]);
    }
}

void ShowArray(int size, int array[Maxsize])
{
    for (i = 0; i < size; i++)
    {
        printf(" %d\t", array[i]);
    }
    printf("\n");
}

void calArray(int size, int array_1[Maxsize], int array_2[Maxsize], int array_3[Maxsize])
{
    for (i = 0; i < size; i++)
    {
        array_3[i] = array_1[i] + array_2[i];
    }
}

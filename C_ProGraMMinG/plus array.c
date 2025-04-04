#include <stdio.h>
#define Maxsize 30
//naphatsorn wattanon 6621600321 sec 700
void main()
{
    int size,i;
    int array_1[Maxsize],array_2[Maxsize],array_3[Maxsize];
    char answer;
    do
    {

        do{
            printf("Please enter size of array: ");
            scanf(" %d", &size);
        	if(size < 2 || size > Maxsize){
				printf("error size and the sizes are betweem 2-30\n");
			}
		}while(size < 2 || size > Maxsize);


        printf("Enter value for array_1\n");
        for (i = 0; i < size; i++)
        {
            array_1[i] = 0;
            printf("Enter value for position [%d]: ", i);
            scanf(" %d", &array_1[i]);
        }

        printf("Enter value for array_2\n");
        for (i = 0; i < size; i++)
        {
            array_2[i] = 0;
            printf("Enter value for position [%d]: ", i);
            scanf(" %d", &array_2[i]);
        }

        printf("\nValue of array_1\n");
        printf("\n");
        for (i = 0; i < size; i++)
        {
            printf("%d\t", array_1[i]);
        }
        printf("\n");

        printf("\nValue of array_2\n");
        printf("\n");
        for (i = 0; i < size; i++)
        {
            printf("%d\t", array_2[i]);
        }
        printf("\n");



        for (i = 0; i < size; i++)
        {
                array_3[i] = array_1[i] + array_2[i];
        }

        printf("\nValue of array_3\n");
        printf("\n");
        for (i = 0; i < size; i++)
        {
                printf(" %d\t", array_3[i]);
        }
        printf("\n");
        printf("\n");


        printf("Do you want to do it again? (y/n): ");
        scanf(" %c", &answer);

    } while (answer == 'y' || answer == 'Y');
}

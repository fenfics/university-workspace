#include <stdio.h>
#define Maxsize 100
//Naphatsorn wattanon 6621600321 sec 700
void main()
{
	  int i,*p,size;
	  int array_Point[Maxsize];
	  float sum,average;
	  char answer;

	do
	    {
	        do
			{
			    printf("Please enter size of array: ");
			    scanf(" %d", &size);
			    if(size < 2 || size > Maxsize){
					printf("!!!error size and the size are between 2-100\n");
				}
			} while (size < 2 || size > Maxsize);


	        printf("Enter value for array\n");
	        for (i = 0; i < size; i++){
					array_Point[i]=0;
	                printf("Enter value for position [%d]: ", i);
	                scanf(" %d", &array_Point[i]);
	        }
			sum = 0;
	        p=&array_Point[0];
	        for(i = 0 ; i < size ; i++){
				sum += *(p+i);
			}

			average = sum / (size);

			printf("Average of array by Pointer is %.2f\n",average);

	        printf("Do you want to do it again? (y/n): ");
	        scanf(" %c", &answer);

	    } while (answer == 'y' || answer == 'Y');
	}
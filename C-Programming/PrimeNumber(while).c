#include<stdio.h>

void main()
{
   int start,end;
   char answer;
   int count;
   do{
	   do{
   		printf("Start from number?: ");
   		scanf(" %d", &start);
   		while(start < 1){
			printf("Invalid number. Please input start again\n");
   			break;
			}
   		}while(start < 1);

		do{
   		printf("End from number?: ");
   		scanf(" %d", &end);
   		while(end <= start){
			printf("Invalid number. Please input End again\n");
   			break;
			}
   		}while(end <= start);

   		printf("Prime numbers between %d to %d are:\n", start, end);
		printf("\n");
   		count = 0;

   		while(start <= end ) {

			while(start == 1){
				start++;
				break;
			}

   			while(start == 2 || start == 3 || start == 5 || start == 7){
				printf("%d\t",start);
				count++;
				break;
			}

			while(start % 2 != 0 && start % 3 != 0 && start % 5 !=0 && start % 7 !=0){
				printf("%d\t",start);
				count++;
				break;
				}

			while(count == 5) {
				printf("\n\n");
				count=0;
				break;
				}
   		start++;
   	}

   	printf("\n");
   	printf("Do you want to do it again?(y/n) ");
   	scanf(" %c", &answer);

   } while (answer == 'y' || answer == 'Y');
}

#include<stdio.h>
//Naphatsorn wattanon 6621600321 sec700
void main()
{
	int start,end;
	char answer;
	int count;
	do{
		do{
		printf("Start from num?(i.e.1,2,3): ");
		scanf(" %d", &start);
		if(start < 1){
			printf("!!!error values please enter start again\n");
			printf("-------------------------\n");
			}
		}while(start < 1);

		do{
		printf("End from num?(i.e.1,2,3): ");
		scanf(" %d",&end);
		if(end <= start){
			printf("The end of the range number must more than start\n");
    		printf("-------------------------\n");
			}
		}while(end <= start);

		printf("Prime numbers between %d to %d are:\n", start, end);
		printf("\n");
		count=0;
		for (start = start ; start <= end ; start++ ){

					if(start == 1){
						continue;
					}

		   			if(start == 2 || start == 3 || start == 5 || start == 7){
						printf("%d\t",start);
						count++;
					}

					if(start % 2 != 0 && start % 3 != 0 && start % 5 !=0 && start % 7 !=0){
						printf("%d\t",start);
						count++;
					}

					if(count == 5) {
						printf("\n\n");
						count = 0;
					}

			}

		 printf("\n");
		 printf("Do you want to do it again?(y/n) ");
		 scanf(" %c", &answer);

		 }while (answer == 'y' || answer == 'Y');
}
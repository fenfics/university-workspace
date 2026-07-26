#include<stdio.h>
int calNumber(int n1,int n2);

void main(){
	int Result1,Result2,Result3;
	Result1 = calNumber(-5,20);
	Result2 = calNumber(30,5);
	Result3 = calNumber(5,-50);

	printf("Result of 10 and 20 is %d\n",Result1);
	printf("Result of 30 and 5 is %d\n",Result2);
	printf("Result of 5 and 42 is %d\n",Result3);
}

int calNumber(int n1, int n2){
	int sum=0;
	sum=n1+n2;
	return(sum);
}


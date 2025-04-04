#include <stdio.h>

void test();

int global_num1 = 10;
float global_num2 = 15.25;

void main() {

    int num1 = 10;
    int num2 = 25;


    printf("Number from main function are %d and %d \n", num1, num2);
    printf("Number from global variable is %d and %0.2f\n", global_num1, global_num2);
    //printf("Number from other function is %d and %d\n",t1,t2);
    printf("-----------------------------------------------------------\n");

    test();

    printf("End of funtionc test\n");

}

void test()
{
    int t1 = 1;
    int t2 = 2;

    printf("Number 1 from test function are %d and  %d \n", t1, t2);
    printf("Number from global variable is %d and %0.2f\n", global_num1, global_num2);
	//printf("Number from other function is %d and %d\n",num1,num2);
	printf("-----------------------------------------------------------\n");
}



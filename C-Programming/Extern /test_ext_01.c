#include <stdio.h>
#include "test_ext_02.c"

extern int ans;
extern int CalPlus(int a, int b);

void ShowMessage(int a);

void main() {
	int result_02;
    int result_01 = CalPlus(2, 5);
    ShowMessage(result_01);

    result_02 = result_01 + ans;
    ShowMessage(result_02);

}

void ShowMessage(int a) {
    printf("The result is %d\n", a);
}

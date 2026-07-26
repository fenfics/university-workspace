#include <stdio.h>

void main() {
    char letter1, letter2, letter3, letter4, letter5,letter6, letter7, letter8, letter9, letter10,temp1, temp2;
    int count;
    char answer;

    do {
		letter6=0, letter7=0, letter8=0, letter9=0, letter10 = 0;

        printf("Please input 5 letters:\n");

        do {
            printf("letter1: ");
            scanf(" %c", &letter1);
        } while (!((letter1 >= 'A' && letter1 <= 'Z') || (letter1 >= 'a' && letter1 <= 'z')));

        do {
            printf("letter2: ");
            scanf(" %c", &letter2);
        } while (!((letter2 >= 'A' && letter2 <= 'Z') || (letter2 >= 'a' && letter2 <= 'z')));

        do {
            printf("letter3: ");
            scanf(" %c", &letter3);
        } while (!((letter3 >= 'A' && letter3 <= 'Z') || (letter3 >= 'a' && letter3 <= 'z')));

        do {
            printf("letter4: ");
            scanf(" %c", &letter4);
        } while (!((letter4 >= 'A' && letter4 <= 'Z') || (letter4 >= 'a' && letter4 <= 'z')));

        do {
            printf("letter5: ");
            scanf(" %c", &letter5);
        } while (!((letter5 >= 'A' && letter5 <= 'Z') || (letter5 >= 'a' && letter5 <= 'z')));


        if (letter1 >= 'A' && letter1 <= 'Z') letter6 = letter1 + 32; else letter6 = letter1;
        if (letter2 >= 'A' && letter2 <= 'Z') letter7 = letter2 + 32; else letter7 = letter2;
        if (letter3 >= 'A' && letter3 <= 'Z') letter8 = letter3 + 32; else letter8 = letter3;
        if (letter4 >= 'A' && letter4 <= 'Z') letter9 = letter4 + 32; else letter9 = letter4;
        if (letter5 >= 'A' && letter5 <= 'Z') letter10 = letter5 + 32; else letter10 = letter5;


        count = 0;
        while (count < 4) {
            if (letter6 > letter7) {
                temp1 = letter6;
                letter6 = letter7;
                letter7 = temp1;

                temp2 = letter1;
                letter1 = letter2;
                letter2 = temp2;
            }
            if (letter7 > letter8) {
                temp1 = letter7;
                letter7 = letter8;
                letter8 = temp1;

                temp2 = letter2;
                letter2 = letter3;
                letter3 = temp2;
            }
            if (letter8 > letter9) {
                temp1 = letter8;
                letter8 = letter9;
                letter9 = temp1;

                temp2 = letter3;
                letter3 = letter4;
                letter4 = temp2;
            }
            if (letter9 > letter10) {
                temp1 = letter9;
                letter9 = letter10;
                letter10 = temp1;

                temp2 = letter4;
                letter4 = letter5;
                letter5 = temp2;
            }
            count++;
        }

        if (letter6 == letter7 && letter1 > letter2) {
            temp1 = letter1;
            letter1 = letter2;
            letter2 = temp1;
        }
        if (letter7 == letter8 && letter2 > letter3) {
            temp1 = letter2;
            letter2 = letter3;
            letter3 = temp1;
        }
        if (letter8 == letter9 && letter3 > letter4) {
            temp1 = letter3;
            letter3 = letter4;
            letter4 = temp1;
        }
        if (letter9 == letter10 && letter4 > letter5) {
            temp1 = letter4;
            letter4 = letter5;
            letter5 = temp1;
        }

		count=0;
		for(count = 0; count < 4 ; count++){
			if(letter6 == letter7 && letter6 == letter8 && letter6 == letter9 && letter6 == letter10 && letter1>letter2){
					temp1=letter1;
					letter1=letter2;
					letter2=temp1;
				}
			if(letter6 == letter7 && letter6 == letter8 && letter6 == letter9 && letter6 == letter10 && letter1>letter3){
					temp1=letter1;
					letter1=letter3;
					letter3=temp1;
				}
			if(letter6 == letter7 && letter6 == letter8 && letter6 == letter9 && letter6 == letter10 && letter1>letter4){
					temp1=letter1;
					letter1=letter4;
					letter4=temp1;
				}
			if(letter6 == letter7 && letter6 == letter8 && letter6 == letter9 && letter6 == letter10 && letter1>letter5){
					temp1=letter1;
					letter1=letter5;
					letter5=temp1;
				}
			if(letter6 == letter7 && letter6 == letter8 && letter1>letter2){
					temp1=letter1;
					letter1=letter2;
					letter2=temp1;
				}
			if(letter7 == letter8 && letter7 == letter9 && letter2>letter3){
					temp1=letter2;
					letter2=letter3;
					letter3=temp1;
				}
			if(letter8 == letter9 && letter8 == letter10 && letter3>letter4){
					temp1=letter3;
					letter3=letter4;
					letter4=temp1;
				}
		}


        printf("Sorted letters: %c %c %c %c %c\n", letter1, letter2, letter3, letter4, letter5);

        printf("\nDo you want to do it again? (y/n): ");
        scanf(" %c", &answer);

    } while (answer == 'y' || answer == 'Y');
}

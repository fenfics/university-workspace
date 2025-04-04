#include <stdio.h>
//Naphatsorn wattanon 6621600321 sec700
void main()
{
    int num_1, num_2, range, sum;
    char ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8, ch9, ch10, ch11, ch12;
    char answer;
    do
    {
        sum = 0, num_1 = 0, num_2 = 0;
        do {
            printf("Input num 1: ");
            scanf(" %c%c", &ch1, &ch2);

            while (ch1 > '0' && ch1 <= '9') {
                while (ch2 == '\n') {
                    num_1 = ch1 - 48;
                    break;
                }
                while (ch2 >= '0' && ch2 <= '9') {
                    scanf("%c", &ch3);
                    while (ch3 == '\n') {
                        num_1 = ((ch1 - 48) * 10) + (ch2 - 48);
                        break;
                    }
                    while (ch3 >= '0' && ch3 <= '9') {
                        scanf("%c", &ch4);
                        while (ch4 == '\n') {
                            num_1 = ((ch1 - 48) * 100) + ((ch2 - 48) * 10) + (ch3 - 48);
                            break;
                        }
                        while (ch4 != '\n') {
                            printf("!!!error input\n");
                            break;
                        }
                        break;
                    }
                    while (ch3 != '\n' && (ch3 < '0' || ch3 > '9')) {
                        printf("!!!error input\n");
                        break;
                    }
                    break;
                }
                while (ch2 != '\n' && (ch2 < '0' || ch2 > '9')) {
                    printf("!!!error input\n");
                    break;
                }
                break;
            }
            while (ch1 <= '0' || ch1 > '9') {
                printf("!!!error input\n");
                break;
            }
        } while (ch1 <= '0' || ch1 >'9' || ch2 <= '0' || ch2 >'9' || ch3 <= '0' || ch3 >'9');

        do {
            printf("Input num 2: ");
            scanf(" %c%c", &ch5, &ch6);

            while (ch5 > '0' && ch5 <= '9') {
                while (ch6 == '\n') {
                    num_2 = ch5 - 48;
                    break;
                }
                while (ch6 >= '0' && ch6 <= '9') {
                    scanf("%c", &ch7);
                    while (ch7 == '\n') {
                        num_2 = ((ch5 - 48) * 10) + (ch6 - 48);
                        break;
                    }
                    while (ch7 >= '0' && ch7 <= '9') {
                        scanf("%c", &ch8);
                        while (ch8 == '\n') {
                            num_2 = ((ch5 - 48) * 100) + ((ch6 - 48) * 10) + (ch7 - 48);
                            break;
                        }
                        while (ch8 != '\n') {
                            printf("!!!error input\n");
                            break;
                        }
                        break;
                    }
                    while (ch7 != '\n' && (ch7 < '0' || ch7 > '9')) {
                        printf("!!!error input\n");
                        break;
                    }
                    break;
                }
                while (ch6 != '\n' && (ch6 < '0' || ch6 > '9')) {
                    printf("!!!error input\n");
                    break;
                }
                break;
            }
            while (ch5 <= '0' || ch5 > '9') {
                printf("!!!error input\n");
                break;
            }
        } while (ch5 <= '0' || ch5 >'9' || ch6 <= '0' || ch6 >'9' || ch7 <= '0' || ch7 >'9');

        do {
            printf("Specify the minimum value for the sum of number 1 and number 2: ");
            scanf(" %c%c", &ch9, &ch10);

            while (ch9 > '0' && ch9 <= '9') {
                while (ch10 == '\n') {
                    range = ch9 - 48;
                    break;
                }
                while (ch10 >= '0' && ch10 <= '9') {
                    scanf("%c", &ch11);
                    while (ch11 == '\n') {
                        range = ((ch9 - 48) * 10) + (ch10 - 48);
                        break;
                    }
                    while (ch11 >= '0' && ch11 <= '9') {
                        scanf("%c", &ch12);
                        while (ch12 == '\n') {
                            range = ((ch9 - 48) * 100) + ((ch10 - 48) * 10) + (ch11 - 48);
                            break;
                        }
                        while (ch12 != '\n') {
                            printf("!!!error input\n");
                            break;
                        }
                        break;
                    }
                    while (ch11 != '\n' && (ch11 < '0' || ch11 > '9')) {
                        printf("!!!error input\n");
                        break;
                    }
                    break;
                }
                while (ch10 != '\n' && (ch10 < '0' || ch10 > '9')) {
                    printf("!!!error input\n");
                    break;
                }
                break;
            }
            while (ch9 <= '0' || ch9 > '9') {
                printf("!!!error input\n");
                break;
            }
        } while (ch9 <= '0' || ch9 >'9' || ch10 <= '0' || ch10 >'9' || ch11 <= '0' || ch11 >'9');

        sum = num_1 + num_2;
        while(sum >= range)
        {
            printf("Good job!!! %d and %d can add them together and get a value %d, it doesn't less than %d \n",num_1, num_2, sum, range);
            break;
        }
        while(sum < range)
        {
            printf("Oh sorry!!! %d and %d can add them together and get a value %d, it less than %d \n",num_1, num_2, sum, range);
            break;
        }
        printf("-------------------------------------------------------------------------------------\n");
        printf("Do you want to do it again?(y/n)");
        scanf(" %c", &answer);
    } while (answer == 'y' || answer == 'Y');
}
#include <stdio.h>

FILE *fptr;
int id;
char name[41];
float score;
int chkEOF;

void main()
{
    /*// Write Data to the File
    fptr = fopen("D:\\fenFiction\\c_programming\\LabSheet-03\\Lab\\Test.dat", "w"); // write
    if (fptr == NULL)
    {
        printf("File can not be opened\n");
        exit(1);
    }
    printf("1: File can be opened\n");
    fprintf(fptr, "%d %s %.2f\n", 111, "Test_01", 2.20);
    fprintf(fptr, "%d %s %.2f\n", 222, "Test_02", 1.25);
    fprintf(fptr, "%d %s %.2f\n", 333, "Test_03", 1.50);
    fprintf(fptr, "%d %s %.2f\n", 444, "Test_04", 1.75);
    fprintf(fptr, "%d %s %.2f\n", 555, "Test_05", 2.00);
    fclose(fptr);*/

	// Read Data from the File
	fptr = fopen("D:\\fenFiction\\c_programming\\LabSheet-03\\Lab\\Test.dat", "r"); // read
	if (fptr == NULL)
	{
    	printf("File can not be opened\n");
    	exit(1);
	}
	printf("2: File can be opened\n");
	while ((chkEOF = fscanf(fptr, "%d %s %f", &id, &name, &score)) != EOF)
	{
    	printf("%d %s %f\n", id, name, score);
	}
	fclose(fptr);
	printf("Final: %d %s %f\n", id, name, score);

}

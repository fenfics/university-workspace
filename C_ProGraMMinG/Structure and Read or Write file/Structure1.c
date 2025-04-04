#include<stdio.h>

struct Employee {
   char id[6];
   char name[41];
   float hour;
   float rate;
};

typedef struct Employee sEmp;

struct CalData {
   float Hr_Rate;
};

typedef struct CalData sCald;

void printdetail(struct Employee empdet);

struct CalData calHourRate(struct Employee emparr[]);

// Start: Example for Typedef
void fprintdetail(sEmp empdet);
sCald fcalHourRate(sEmp emparr[]);
// End: Example for Typedef

// Start: Example for Union
union myunion{
   int idata;
   float fdata;
};
// End: Example for Union

main()
{
   // Start: Pointer in structured data type
   struct Employee emp = {"4401", "Somsri", 40, 80};
   sEmp demp = {"4451", "Somsri", 555, 666};
   struct Employee *ptr = &emp;
   printf("1: ID = %s\nName = %s\nHour = %f\nRate = %f\n",
   ptr->id, ptr->name, ptr->hour, ptr->rate);
   printf("2: ID = %s\nName = %s\nHour = %f\nRate = %f\n",
   (*ptr).id, (*ptr).name, (*ptr).hour, (*ptr).rate);
   // End: Pointer in structured data type
}

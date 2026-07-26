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
    // Start : Function in Structured Data Types
	struct Employee emp = {"4401", "Somsri", 40, 80};
    sEmp demp = {"4401", "Somsri", 40, 80};
    struct Employee emp_array[3];
    struct CalData ans;
    sCald dans;

    printf("ID: ");
    scanf("%s", &emp_array[0].id);
    printf("Name: ");
    scanf("%s", &emp_array[0].name);
    printf("Hour: ");
    scanf("%f", &emp_array[0].hour);
    printf("Rate: ");
    scanf("%f", &emp_array[0].rate);
    printf("3: ID = %s\nName = %s\nHour = %f\nRate = %f\n",
    emp_array[0].id, emp_array[0].name,
    emp_array[0].hour, emp_array[0].rate);
    printdetail(emp);
    ans = calHourRate(emp_array);
    printf("5: Result = %f\n", ans.Hr_Rate);
    // End : Function in Structured Data Types

    // Start : Typedef + Function in Structured Data Types
    fprintdetail(demp);
    dans = fcalHourRate(emp_array);
    printf("7: Result = %f\n", dans.Hr_Rate);
    // End : Typedef + Function in Structured Data Types
}
void printdetail(struct Employee empdet)
{
    // Start
    printf("4: ID = %s\nName = %s\nHour = %f\nRate = %f\n",
    empdet.id, empdet.name, empdet.hour, empdet.rate);
    // End
}
struct CalData calHourRate(struct Employee emparr[])
{
    // Start
    struct CalData result;
    result.Hr_Rate = emparr[0].hour * emparr[0].rate;
    return result;
    // End
}
void fprintdetail(sEmp empdet)
{
    // Start
    printf("6: ID = %s\nName = %s\nHour = %f\nRate = %f\n",
    empdet.id, empdet.name, empdet.hour, empdet.rate);
    // End
}
sCald fcalHourRate(sEmp emparr[])
{
    // Start
    sCald result;
    result.Hr_Rate = emparr[0].hour * emparr[0].rate;
    return result;
    // End
}

#include<stdio.h>

typedef struct Time
{
    int hour;
    int minute;
}time;

void addTime(time t1, time t2, time *result)
{
    result->hour = (t2.hour - t1.hour)*60;
    result->minute = t2.minute - t1.minute;
}

int main()
{
    struct Time time1, time2, result;

    printf("\nEnter time\n");
    printf("\nEnter Hour : ");
    scanf("%d", &time1.hour);
    printf("Enter Minutes : ");
    scanf("%d", &time1.minute);
    printf("===============");
    printf("\nEnter time");
    printf("\nEnter Hour : ");
    scanf("%d", &time2.hour);
    printf("Enter Minutes : ");
    scanf("%d", &time2.minute);

    addTime(time1, time2, &result);

    printf("===============\n");
    printf("First hour : %d:%d\n", time1.hour, time1.minute);
    printf("Second hour : %d:%d\n", time2.hour, time2.minute);
    printf("Result : %d", result.hour+result.minute);
};

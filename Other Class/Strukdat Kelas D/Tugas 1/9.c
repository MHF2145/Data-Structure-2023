#include <stdio.h>

typedef struct Length
{
    int meter;
    int cm;
} length;

void addlength(length l1, length l2, length *result)
{
    result->meter = (l2.meter + l1.meter) * 100;
    result->cm = l2.cm + l1.cm;
}
void subtractlength(length l1, length l2, length *result)
{
    if (l2.meter >= l1.meter)
    {
        result->meter = (l2.meter - l1.meter) * 100;
        if (l2.cm > l1.cm)
        {
            result->cm = l2.cm - l1.cm;
        }
        else if (l1.cm > l2.cm)
        {
            result->cm = l1.cm - l2.cm;
        }
    }
    else if (l1.meter > l2.meter)
    {
        result->meter = (l1.meter - l2.meter) * 100;
        if (l2.cm > l1.cm)
        {
            result->cm = l2.cm - l1.cm;
        }
        else if (l1.cm > l2.cm)
        {
            result->cm = l1.cm - l2.cm;
        }
    }
}

int main()
{
    struct Length l1, l2, result;

    printf("\nEnter length\n");
    printf("\nEnter meter : ");
    scanf("%d", &l1.meter);
    printf("Enter cms : ");
    scanf("%d", &l1.cm);
    printf("===============");
    printf("\nEnter length");
    printf("\nEnter meter : ");
    scanf("%d", &l2.meter);
    printf("Enter cms : ");
    scanf("%d", &l2.cm);

    addlength(l1, l2, &result);

    printf("===============\n");
    printf("First meter : %d meter, %d cm\n", l1.meter, l1.cm);
    printf("Second meter : %d meter, %d cm\n", l2.meter, l2.cm);
    printf("Result (Added) : %d\n", result.meter+result.cm);
    printf("Result (Subtracted) : %d", result.meter-result.cm);
};
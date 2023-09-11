#include <stdio.h>
struct date
{
    int dd, mm, yy;
};
int date_cmp(struct date d1, struct date d2);
void date_print(struct date d);
int main()
{
    struct date d1 = {7, 3, 2005};
    struct date d2 = {24, 10, 2005};
    date_print(d1);
    int cmp = date_cmp(d1, d2);
    if (cmp == 0)
        printf(" is equal to");
    else if (cmp > 0)
        printf(" is greater i.e. later than ");
    else
        printf(" is smaller i.e. earlier than");
    date_print(d2);
    return 0;
}

int date_cmp(struct date d1, struct date d2)
{
    if (d1.dd == d2.dd && d1.mm == d2.mm && d1.yy == d2.yy)
        return 0;
    else if (d1.yy > d2.yy || d1.yy == d2.yy && d1.mm > d2.mm ||
             d1.yy == d2.yy && d1.mm == d2.mm && d1.dd > d2.dd)
        return 1;
    else
        return -1;
}

void date_print(struct date d)
{
    printf("%d/%d/%d", d.dd, d.mm, d.yy);
}
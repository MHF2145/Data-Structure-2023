#ifndef A0_DATE_H_
#define A0_DATE_H_

static const char monthNames[12][4] = {
    "Jan", "Feb", "Mar", "Apr",
    "May", "Jun", "Jul", "Aug",
    "Sep", "Oct", "Nov", "Dec"
};

typedef struct {
    unsigned char date;
    unsigned char month;
    unsigned short year;
} Date;

int DateCompare(Date a, Date b);

#endif // A0_DATE_H_
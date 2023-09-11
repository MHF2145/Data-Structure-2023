#include "Date.h"

int DateCompare(Date a, Date b)
{
    if (a.year < b.year) {
        return -1;
    }
    else if (a.year > b.year) {
        return 1;
    }
    
    if (a.month < b.month) {
        return -1;
    }
    else if (a.month > b.month) {
        return 1;
    }

    if (a.date < b.date) {
        return -1;
    }
    else if (a.date > b.date) {
        return 1;
    }

    return 0;
}
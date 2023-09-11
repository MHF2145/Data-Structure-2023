#include <stdio.h>
#include <assert.h>
#include "../Assert.h"
#include "Date.h"

int main()
{
    // All dates are in D(D)/M(M)/YYYY

    Date a;
    Date b;

    // Case 1: 19/09/2004 and 21/05/2005 (different year), should return -1
    a = (Date){19, 9, 2004};
    b = (Date){21, 5, 2005};
    A0_ASSERT(DateCompare(a, b) == -1, "a comes BEFORE b");

    // Case 2: 19/09/2004 and 19/10/2004 (different month), should return -1
    a = (Date){19, 9, 2004};
    b = (Date){19, 10, 2004};
    A0_ASSERT(DateCompare(a, b) == -1, "a comes BEFORE b");

    // Case 3: 19/09/2004 and 20/09/2004 (different day), should return -1
    a = (Date){19, 9, 2004};
    b = (Date){20, 10, 2004};
    A0_ASSERT(DateCompare(a, b) == -1, "a comes BEFORE b");

    // Case 4: 01/01/2001 and 01/01/2001 (no difference), should return 0
    a = (Date){1, 1, 2001};
    b = (Date){1, 1, 2001};
    A0_ASSERT(DateCompare(a, b) == 0, "a is THE SAME as b");

    // Case 5: 20/12/2003 and 01/05/2002 (different year), should return 1
    a = (Date){20, 12, 2003};
    b = (Date){1 , 5 , 2002};
    A0_ASSERT(DateCompare(a, b) == 1, "a comes AFTER b");

    // Case 6: 20/12/2002 and 01/05/2002 (different month), should return 1
    a = (Date){20, 12, 2002};
    b = (Date){01, 5 , 2002};
    A0_ASSERT(DateCompare(a, b) == 1, "a comes AFTER b");

    // Case 7: 20/05/2002 and 01/05/2002 (different day), should return 1
    a = (Date){20, 5 , 2002};
    b = (Date){1 , 5 , 2002};
    A0_ASSERT(DateCompare(a, b) == 1, "a comes AFTER b");

    A0_MAKE_SUMMARY();
    return 0;
}
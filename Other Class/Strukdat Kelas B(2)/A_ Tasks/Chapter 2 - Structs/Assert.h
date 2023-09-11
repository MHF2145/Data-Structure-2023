#ifndef A0_ASSERT_H_
#define A0_ASSERT_H_

#include <stdio.h>

static int s_TestCases = 0;
static int s_PassedCases = 0;
static int s_FailedCases = 0;

#define A0_COLOR_MODE_NORMAL "\e[0m"
#define A0_COLOR_MODE_ERROR "\e[1;31m"
#define A0_COLOR_MODE_SUCCESS "\e[1;32m"
#define A0_COLOR_MODE_INFO "\e[1;34m"

#define A0_ASSERT(CONDITION, FAILED_MSG) \
    ++s_TestCases; \
    if (!(CONDITION)) { \
        fprintf(stderr, "%s[TEST CASE #%d] FAILED:%s Assertion failed at %s line %d: %s.\n", \
                A0_COLOR_MODE_ERROR, s_TestCases, A0_COLOR_MODE_NORMAL, __FILE__, __LINE__, (FAILED_MSG)); \
        ++s_FailedCases; \
    } \
    else { \
        fprintf(stdout, "%s[TEST CASE #%d] PASSED.%s\n", \
                A0_COLOR_MODE_SUCCESS, s_TestCases, A0_COLOR_MODE_NORMAL); \
        ++s_PassedCases; \
    } \
        
#define A0_MAKE_SUMMARY() \
    printf("\n%s[%d/%d] TEST CASES PASSED (%d FAILED).%s\n", \
            A0_COLOR_MODE_INFO, s_PassedCases, s_TestCases, s_FailedCases, A0_COLOR_MODE_NORMAL); \

#endif // A0_ASSERT_H_
#include <stdio.h>
#include <string.h>
#include "Stall.h"

int main()
{
    StallReport reportsFromFile[10];
    int reportsFromFileCount = ReadReportsFrom("input.txt", reportsFromFile);
    SortStallReport(reportsFromFile, reportsFromFileCount);

    printf("Reports from File: \n");
    PrintSalesSummary(reportsFromFile, reportsFromFileCount);


    StallReport reportsFromCode[3];

    InsertReportInto(&reportsFromCode[0], "Stall #1", 400.00, 500.00);
    InsertReportInto(&reportsFromCode[1], "Stall #2", 100.00, 200.00);
    InsertReportInto(&reportsFromCode[2], "Stall #3", 500.00, 450.00);
    SortStallReport(reportsFromCode, 3);

    printf("\n\nReports from Code: \n");
    PrintSalesSummary(reportsFromCode, 3);
}
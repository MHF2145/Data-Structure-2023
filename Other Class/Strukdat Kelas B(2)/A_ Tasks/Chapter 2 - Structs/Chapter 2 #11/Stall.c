#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stall.h"

int ReadReportsFrom(const char* path, StallReport* reports)
{
    FILE* reportFile = fopen(path, "r");

    if (!reportFile) {
        fprintf(stderr, "ERROR: File does not exist.");
        exit(EXIT_FAILURE);
    }

    int reportCount = 0;

    while (1) {
        StallReport temp_Report;
        
        fscanf(reportFile, "%s", temp_Report.stallName);
        if (strcmp(temp_Report.stallName, "xxxxxx") == 0) {
            break;
        }
        fscanf(reportFile, "%lf %lf", &temp_Report.income, &temp_Report.expense);
        temp_Report.profit = temp_Report.income - temp_Report.expense;

        strcpy(reports[reportCount].stallName, temp_Report.stallName);
        reports[reportCount].income = temp_Report.income;
        reports[reportCount].expense = temp_Report.expense;
        reports[reportCount].profit = temp_Report.profit;
        reportCount++;
    }

    fclose(reportFile);
    return reportCount;
}

void __StallReportSwap(StallReport *a, StallReport *b)
{
    StallReport temp = *a;
    *a = *b;
    *b = temp;
}

int __StallReportPartition(StallReport *reports, int low, int high)
{
    double pivot = reports[high].profit;

    int i = (low-1);  
    for (int j = low; j < high; j++) {
        if (reports[j].profit > pivot) {
            i++;
            __StallReportSwap(&reports[i], &reports[j]);
        }
    }   
    __StallReportSwap(&reports[i+1], &reports[high]);

    return (i+1);
}


void __StallReportQuickSort(StallReport* reports, int low, int high)
{
    if (low < high) {
        int mid = __StallReportPartition(reports, low, high);
        __StallReportQuickSort(reports, low, mid - 1);    
        __StallReportQuickSort(reports, mid + 1, high);
    }
}

void SortStallReport(StallReport* reports, int reportCount)
{
    __StallReportQuickSort(reports, 0, reportCount-1);
}

void InsertReportInto(StallReport* report, const char* stallName, double income, double expense)
{
    strncpy(report->stallName, stallName, 50);
    report->income = income;
    report->expense = expense;
    report->profit = income - expense;
}

void PrintSalesSummary(StallReport* reports, int reportCount)
{
    double totalProfit = 0.0;

    printf("---------------------------------------------------------------------------\n");
    printf("| %-20s | %-14s | %-14s | %-14s |\n", "Stall Name", "Income", "Expense", "Gain/Loss");
    printf("---------------------------------------------------------------------------\n");
    for (int i = 0; i < reportCount; i++) {
        printf("| %-20s | %-14.2lf | %-14.2lf | %-14.2lf |\n", reports[i].stallName, reports[i].income, reports[i].expense, reports[i].profit);
        totalProfit += reports[i].profit;
    }
    printf("---------------------------------------------------------------------------\n");

    printf("\nTotal Stalls  : %d", reportCount);
    if (totalProfit > 0) {
        printf("\nTotal Profit  : %.2lf\n", totalProfit);
    }
    else {
        printf("\nTotal Loss    : %.2lf\n", -totalProfit);
    }
    printf("Top Gainer    : %s\n", reports[0].stallName);
}
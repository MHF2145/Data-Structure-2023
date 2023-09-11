#ifndef A0_STALL_H_
#define A0_STALL_H_

typedef struct {
    char stallName[51];
    double income;
    double expense;
    double profit;
} StallReport;

int ReadReportsFrom(const char* path, StallReport* reports);
void SortStallReport(StallReport* reports, int reportCount);
void InsertReportInto(StallReport* report, const char* stallName, double income, double expense);
void PrintSalesSummary(StallReport* reports, int reportCount);

#endif // A0_STALL_H_
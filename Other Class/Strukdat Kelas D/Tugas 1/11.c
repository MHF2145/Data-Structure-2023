#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stall
{
    char name[50];
    float income;
    float expenses;
};

float net_income(struct Stall stall)
{
    return stall.income - stall.expenses;
}

int main()
{
    struct Stall stalls[100];
    int num_stalls = 0;
    float total_profit = 0.0;
    float max_profit = -1.0;
    char max_profit_stalls[100][50];
    int num_max_profit_stalls = 0;

    while (1)
    {
        char name[50];
        float income, expenses;
        scanf("%s", name);
        if (strcmp(name, "xxxxxx") == 0)
        {
            break;
        }
        scanf("%f %f", &income, &expenses);
        strcpy(stalls[num_stalls].name, name);
        stalls[num_stalls].income = income;
        stalls[num_stalls].expenses = expenses;
        total_profit += net_income(stalls[num_stalls]);
        if (net_income(stalls[num_stalls]) > max_profit)
        {
            max_profit = net_income(stalls[num_stalls]);
            num_max_profit_stalls = 0;
            strcpy(max_profit_stalls[num_max_profit_stalls], stalls[num_stalls].name);
            num_max_profit_stalls++;
        }
        else if (net_income(stalls[num_stalls]) == max_profit)
        {
            strcpy(max_profit_stalls[num_max_profit_stalls], stalls[num_stalls].name);
            num_max_profit_stalls++;
        }
        num_stalls++;
    }

    for (int i = 0; i < num_stalls - 1; i++)
    {
        for (int j = 0; j < num_stalls - i - 1; j++)
        {
            if (net_income(stalls[j]) < net_income(stalls[j + 1]))
            {
                struct Stall temp = stalls[j];
                stalls[j] = stalls[j + 1];
                stalls[j + 1] = temp;
            }
        }
    }

    printf("Number of stalls: %d\n", num_stalls);
    printf("Total profit: %.2f\n", total_profit);
    printf("Stall(s) with the most profit:\n");
    for (int i = 0; i < num_max_profit_stalls; i++)
    {
        printf("%s\n", max_profit_stalls[i]);
    }
    printf("Stall report (sorted by net income):\n");
    for (int i = 0; i < num_stalls; i++)
    {
        printf("%s %.2f\n", stalls[i].name, net_income(stalls[i]));
    }

    return 0;
}

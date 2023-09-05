#include <stdio.h>
#include <string.h>

typedef struct Dictionary
{
    char english[101];
    char indonesian[101];
} dict;

int main()
{
    int n, k;
    printf("\nData to be inputed:");
    scanf("%d", &n);

    struct Dictionary wordinsert[n], wordsearch[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter english : ");
        scanf("%s", &wordinsert[i].english);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter indonesian : ");
        scanf("%s", &wordinsert[i].indonesian);
    }

    printf("\nData to be searched:");
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        printf("\nEnter english : ");
        scanf("%s", &wordsearch[i].english);
    }
    for (int i = 0; i < k; i++)
    {
        printf("\nEnter indonesian : ");
        scanf("%s", &wordsearch[i].indonesian);
    }

    
};
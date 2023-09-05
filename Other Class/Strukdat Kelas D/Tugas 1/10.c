#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct JumpData
{
    int no;
    char name[50];
    int distance;
} data;

int cmp(const void *s1, const void *s2)
{
  double dst1 = ((struct JumpData *)s1)->distance;
  double dst2 = ((struct JumpData *)s2)->distance;

  return (dst2 > dst1) - (dst2 < dst1);
}

int main()
{
    int i, n;
    printf("\nData to be inputed:");
    scanf("%d", &n);

    struct JumpData jump[n];
    printf("Enter Records of %d person", n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Name:");
        scanf("%s", &jump[i].name);
        printf("\nEnter distance:");
        scanf("%d", &jump[i].distance);
    }

    qsort( jump, n, sizeof( struct JumpData ), cmp );

    printf("\nJump records");
    for (i = 0; i < n; i++)
    {
        printf("Name:%s, distance:%d", jump[i].name, jump[i].distance);
    }
    return 0;
}
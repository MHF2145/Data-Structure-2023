#include <stdio.h>
#include <math.h>

int main()
{
    int n, p, w;
    scanf("%d %d %d", &n, &p, &w);
    float t[n], total = 0;
    float ans;

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &t[i]);
        total = total + t[i];
    }

    ans = (total - (p * w)) / 60;
    printf("%.2f\n", ans);
}
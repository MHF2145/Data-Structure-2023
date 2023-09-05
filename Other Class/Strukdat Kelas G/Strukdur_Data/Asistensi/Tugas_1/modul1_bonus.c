#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int count;

void solve(int lg, char input[])
{
    int buka = 0, tutup = 0;
    count = 0;
    for (int i = 0; i < lg; i++)
    {
        if (input[i] == '(' && input[i + 1] == ')')
        {
            i++;
            continue;
        }
        if (input[i] == '(')
        {
            buka++;
        }
        if (input[i] == ')')
        {
            tutup++;
            if (tutup > buka)
            {
                tutup--;
                count++;
            }
        }
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int lg;
        scanf("%d", &lg);
        char input[lg];
        scanf("%s", input);
        solve(lg, input);
        printf("%d\n", count);
    }

    return 0;
}
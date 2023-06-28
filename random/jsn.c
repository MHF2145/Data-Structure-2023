#include <stdio.h>
#include <stdlib.h>

void calculateFact(long long int fact[], long long int N)
{
    fact[0] = 1;
    for (long long int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

long long int nCr(long long int fact[], long long int N, long long int R)
{
    if (R > N)
        return 0;

    long long int res = fact[N] / fact[R];
    res /= fact[N - R];

    return res;
}

long long int countWays(long long int arr[], long long int N, long long int fact[])
{
    if (N <= 2) {
        return 1;
    }

    long long int leftSubTree[N];
    long long int rightSubTree[N];

    long long int root = arr[0];
    long long int leftSize = 0;
    long long int rightSize = 0;

    for (long long int i = 1; i < N; i++) {

        if (arr[i] < root) {
            leftSubTree[leftSize++] = arr[i];
        }

        else {
            rightSubTree[rightSize++] = arr[i];
        }
    }

    long long int countLeft
        = countWays(leftSubTree, leftSize, fact);
    long long int countRight
        = countWays(rightSubTree, rightSize, fact);

    return nCr(fact, N - 1, leftSize)
        * countLeft * countRight;
}

int main()
{
    long long int N;
    scanf("%lld", &N);

    long long int arr[N];
    for (long long int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    long long int fact[N];
    calculateFact(fact, N);

    printf("%lld", (countWays(arr, N, fact)-1)%1000000007);

    return 0;
}

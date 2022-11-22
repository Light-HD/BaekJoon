#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (1000000)
int N;
int A[MAXN];

void InputData()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &A[i]);
    }
}
void Solve()
{
    int changed = 0;
    for (int i = 1; i <= N + 1; i++)
    {
        changed = 0;
        for (int j = 1; j <= N - i; j++)
        {
            if(A[j] > A[j + 1]){
                changed = 1;
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
        if(!changed){
            printf("%d\n", i);
            break;
        }
    }
}
int main()
{

    InputData();

    Solve();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (1000000)
int ans;
int N;
int arr[MAXN + 10];
int ck[MAXN + 10];
int numck[MAXN + 10];
void InputData()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    
}
void OutputData()
{
   printf("%d\n", ans);
}

void SubSet(int cnt)
{
    if(cnt >= N){
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            if(ck[i]){
                sum += arr[i];
            }
        }
        numck[sum] = 1;
        return;
    }
    ck[cnt] = 1;
    SubSet(cnt + 1);
    ck[cnt] = 0;
    SubSet(cnt + 1);
}
void Solve()
{
    SubSet(0);
    int i = 1;
    while(1){
        if(!numck[i]) {
            ans = i;
            return;
        }
        i++;
    }
    
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}

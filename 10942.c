#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (3000)
#define MAXM (1000000)
int ans;
int N, M;
int num[MAXN];
int dp[MAXN][MAXN];

void OutputData()
{
   printf("%d\n", ans);
}

void Solve(int st, int ed)
{
    if(dp[st][ed]){
        ans = 1;
        return;
    }
    int sp = st;
    int ep = ed;
    while(st < ed){
        if(num[st] != num[ed]){
            ans = 0;
            return;
        }
        st++;
        ed--;
    }
    while(sp < ep){
        dp[sp][ep] = 1;
        sp++;
        ep--;
    }
    ans = 1;
}
void InputData()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &num[i]);
    }
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        int st, ed;
        scanf("%d %d", &st, &ed);

        Solve(st, ed);

        OutputData();
    }
    
}
int main()
{

    InputData();

    return 0;
}

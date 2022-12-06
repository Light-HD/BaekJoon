#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (100000)
int ans;
int N;
int arr[3][MAXN + 10];
int dp[3][MAXN + 10];
void InputData()
{
    scanf("%d", &N);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &arr[i][j]);    
        }
    }
}
void OutputData()
{
   printf("%d\n", ans);
}

void Solve()
{
    memset(dp, 0, sizeof(dp));

    dp[0][1] = arr[0][1];
    dp[1][1] = arr[1][1];

    for (int j = 2; j <= N; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            if(dp[(i+1)%2][j-1] > dp[(i+1)%2][j-2]){
                dp[i][j] = arr[i][j] + dp[(i+1)%2][j-1];
            }
            else{
                dp[i][j] = arr[i][j] + dp[(i+1)%2][j-2];
            }
        }
    }

    ans = dp[0][N] > dp[1][N] ? dp[0][N] : dp[1][N];
    
}
int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        InputData();

        Solve();

        OutputData();
    }

    return 0;
}

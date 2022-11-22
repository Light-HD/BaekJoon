#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (60)
int ans;
int N, M;
int A[MAXN][MAXN];
int B[MAXN][MAXN];
void InputData()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d",&A[i][j]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d",&B[i][j]);
        }  
    }
}
void OutputData()
{
   printf("%d\n", ans);
}
void change(int sr, int sc){
    for (int i = sr; i < sr + 3; i++)
    {
        for (int j = sc; j < sc + 3; j++)
        {
            A[i][j] = !A[i][j];
        }
        
    }
    
}
void Solve()
{
    int cnt = 0;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = 0; j < M - 2; j++)
        {
            if(A[i][j] != B[i][j]){
                change(i, j);
                cnt++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(A[i][j] != B[i][j]) {
                ans = -1;
                return;
            }
        }
    }

    ans = cnt;
    return;
    
    
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}

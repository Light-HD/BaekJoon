#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (1000)
int ans = -1;
int N, M;
int arr[MAXN + 10][MAXN + 10];
int dp[MAXN + 10][MAXN + 10][2];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

typedef struct{
    int r, c, k, cnt;
}Point;
Point que[MAXN * MAXN * 2 + 10];
int wp, rp;
void push(int r, int c, int k, int cnt){
    Point p = {r, c, k, cnt};
    que[wp++] = p;
}
Point front(){
    return que[rp];
}
void pop(){
    rp++;
}
int empty(){
    return wp == rp;
}
void InputData()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d",&arr[i][j]);
        }
    }
}
void OutputData()
{
   printf("%d\n", ans);
}

void BFS(){
    push(0, 0, 0, 1);
    dp[0][0][0] = 1;
    while(!empty()){
        Point p = front();
        pop();
        int r = p.r;
        int c = p.c;
        int k = p.k;
        int cnt = p.cnt;

        for (int i = 0; i < 4; i++)
        {
            int flag = 0;
    
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(dp[nr][nc][k] != 0x7fffffff) continue;

            if(arr[nr][nc] == 1){
                if(k == 0) {
                    k = 1;
                    flag = 1;
                }
                else continue;
            }

            if(nr == N - 1 && nc == M - 1){
                ans = cnt + 1;
                return;
            }

            dp[nr][nc][k] = cnt + 1;
            push(nr, nc, k, cnt + 1);
            if(flag) k = 0;
        }
    }

}

void Solve()
{
    if(N == 1 && M == 1) {
        ans = 1;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                dp[i][j][k] = 0x7fffffff;
            }
        }
    }
    
    BFS();
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (50)
int ans = -1;
int N, M;
char arr[MAXN + 10][MAXN + 10];
int ck[MAXN + 10][MAXN + 10][64];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int sr, sc;

typedef struct{
    int r, c, k, cnt;
}Point;
Point que[MAXN * MAXN * 64 + 10];
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
        scanf("%s", arr[i]);
    }
}
void OutputData()
{
   printf("%d\n", ans);
}

void BFS()
{
    push(sr, sc, 0, 0);
    ck[sr][sc][0] = 1;
    while(!empty()){
        Point p = front();
        pop();
        int r = p.r;
        int c = p.c;
        int k = p.k;
        int cnt = p.cnt;

        for (int i = 0; i < 4; i++)
        {
            int cpyk = k;
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(arr[nr][nc] == '#') continue;
            if(ck[nr][nc][cpyk]) continue;

            if(arr[nr][nc] >= 'a' && arr[nr][nc] <= 'f'){
                cpyk |= 1 << (arr[nr][nc] - 'a');
            }

            if(arr[nr][nc] >= 'A' && arr[nr][nc] <= 'F'){
                if(cpyk & 1 << (arr[nr][nc] - 'A'))
                {
                    ;
                }
                else continue;
            }

            if (arr[nr][nc] == '1'){
                ans = cnt + 1;
                return;
            }

            ck[nr][nc][cpyk] = 1;
            push(nr, nc, cpyk, cnt + 1);
        }
    }
}

void Solve()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(arr[i][j] == '0'){
                sr = i;
                sc = j;
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

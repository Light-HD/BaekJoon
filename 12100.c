#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (30)

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int flag;
int ans;
int N;
int map[MAXN][MAXN];
int dr[] = {1, -1, 0, 0}; // 하, 상, 우, 좌
int dc[] = {0, 0, 1, -1};
int arr[MAXN];

void InputData()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    
}
void OutputData()
{
    printf("%d\n", ans);
}

void SumMove(int dir)
{
    switch (dir)
    {
    case UP:
        for (int c = 0; c < N; c++)
        {
            int br = 0;
            int bval = 0;
            for (int r = 0; r < N; r++)
            {
                if(map[r][c] != 0){
                    if(bval == map[r][c]){
                        map[br][c] *= 2;
                        map[r][c] = 0;
                        br = 0;
                        bval = 0;
                    }
                    else {
                        br = r;
                        bval = map[br][c];
                    }
                }
            }
        }

        for (int c = 0; c < N; c++)
        {
            int temp[MAXN];
            int idx = 0;
            for (int r = 0; r < N; r++)
            {
                if(map[r][c] != 0){
                    temp[idx++] = map[r][c];
                    map[r][c] = 0;
                }
            }

            for (int r = 0; r < idx; r++)
            {
                map[r][c] = temp[r];
            }
        }
        break;
    
    case DOWN:
        for (int c = 0; c < N; c++)
        {
            int br = 0;
            int bval = 0;
            for (int r = N-1; r >= 0; r--)
            {
                if(map[r][c] != 0){
                    if(bval == map[r][c]){
                        map[br][c] *= 2;
                        map[r][c] = 0;
                        br = 0;
                        bval = 0;
                    }
                    else {
                        br = r;
                        bval = map[br][c];
                    }
                }
            }
        }

        for (int c = 0; c < N; c++)
        {
            int temp[MAXN];
            int idx = 0;
            for (int r = N-1; r >= 0; r--)
            {
                if(map[r][c] != 0){
                    temp[idx++] = map[r][c];
                    map[r][c] = 0;
                }
            }

            for (int r = 0; r < idx; r++)
            {
                map[(N-1)-r][c] = temp[r];
            }
        }
        break;

    case LEFT:
        for (int r = 0; r < N; r++)
        {
            int bc = 0;
            int bval = 0;
            for (int c = 0; c < N; c++)
            {
                if(map[r][c] != 0){
                    if(bval == map[r][c]){
                        map[r][bc] += map[r][c];
                        map[r][c] = 0;
                        bc = 0;
                        bval = 0;
                    }
                    else {
                        bc = c;
                        bval = map[r][bc];
                    }
                }
            }
        }

        for (int r = 0; r < N; r++)
        {
            int temp[MAXN];
            int idx = 0;
            for (int c = 0; c < N; c++)
            {
                if(map[r][c] != 0){
                    temp[idx++] = map[r][c];
                    map[r][c] = 0;
                }
            }

            for (int c = 0; c < idx; c++)
            {
                map[r][c] = temp[c];
            }
        }
        break;

    case RIGHT:
        for (int r = 0; r < N; r++)
        {
            int bc = 0;
            int bval = 0;
            for (int c = N-1; c >= 0; c--)
            {
                if(map[r][c] != 0){
                    if(bval == map[r][c]){
                        map[r][bc] *= 2;
                        map[r][c] = 0;
                        bc = 0;
                        bval = 0;
                    }
                    else {
                        bc = c;
                        bval = map[r][bc];
                    }
                }
            }
        }

        for (int r = 0; r < N; r++)
        {
            int temp[MAXN];
            int idx = 0;
            for (int c = N-1; c >= 0; c--)
            {
                if(map[r][c] != 0){
                    temp[idx++] = map[r][c];
                    map[r][c] = 0;
                }
            }

            for (int c = 0; c < idx; c++)
            {
                map[r][(N-1)-c] = temp[c];
            }
        }
        break;
    }
}

void DFS(int cnt)
{
    if(cnt >= 5){
        int max = 0;
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                max = max > map[r][c] ? max : map[r][c];
            }
        }
        ans = ans > max ? ans : max;
        return;
    }

    int cpymap[MAXN][MAXN];
    memcpy(cpymap, map, sizeof(map));
    for (int i = 0; i < 4; i++)
    {
        arr[cnt] = i;
        SumMove(i);
        DFS(cnt + 1);
        memcpy(map, cpymap, sizeof(cpymap));
    }
    
}
void Solve()
{
    DFS(0);
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}

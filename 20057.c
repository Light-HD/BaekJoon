#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (510)
int ans;
int N;
int A[MAXN][MAXN];
int ck[MAXN][MAXN];
int dr[] = {0, 1, 0, -1};
int dc[] = {-1, 0, 1, 0};
int sand_dr[4][10] = {{-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}, {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1}, 
                    {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}, {1, 1, 0, 0, 0, 0, -1, -1, -2, -1}};
int sand_dc[4][10] = {{1, 1, 0, 0, 0, 0, -1, -1, -2, -1}, {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0},
                    {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1}, {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}};
int percent[] = {1, 1, 7, 7, 2, 2, 10, 10, 5, 0};

void InputData()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
}
void OutputData()
{
    printf("%d\n", ans);
}
void print_sand()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void calc_sand(int yr, int yc, int d)
{
    int ori_sand = A[yr][yc];
    for (int i = 0; i < 10; i++)
    {
        int nr = yr + sand_dr[d][i];
        int nc = yc + sand_dc[d][i];
        int per = percent[i];
        
        if(per == 0){
            if(nr < 0 || nc < 0 || nr >= N || nc >= N)
            {
                ans += A[yr][yc];
            }
            else A[nr][nc] += A[yr][yc];
            A[yr][yc] = 0;
            break;
        }

        int fly_sand = per * ori_sand * 0.01;
        if(fly_sand == 0) continue;
        A[yr][yc] -= fly_sand;


        if(nr < 0 || nc < 0 || nr >= N || nc >= N){
            ans += fly_sand;
            continue;
        }

        A[nr][nc] += fly_sand;
    }
    
}
void move_tornado()
{
    int r = N/2;
    int c = N/2;
    ck[r][c] = 1;

    int d = 0;
    while(1)
    {
        if(r <= 0 && c <= 0) {
            break;
        }

        int nr = r + dr[d];
        int nc = c + dc[d];

        if(ck[nr][nc]){
            d--;
            if(d < 0) d = 3;

            nr = r + dr[d];
            nc = c + dc[d];
        }

        ck[nr][nc] = 1;
        calc_sand(nr, nc, d);
        r = nr;
        c = nc;
        d = (d + 1) % 4;
    }
}
void Solve()
{
    move_tornado();
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}

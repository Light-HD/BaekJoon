#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (100)
int ans;
int N, M;
int A[MAXN + 10][MAXN + 10];
int cloud[MAXN + 10][MAXN + 10];
int cmd[MAXN + 10][2];
int dr[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int water_bug_dr[] = {-1, 1, 1, -1};
int water_bug_dc[] = {-1, 1, -1, 1};
void InputData()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 1; i <= M; i++)
    {
        scanf("%d %d", &cmd[i][0], &cmd[i][1]);
    }
    
    
}
void OutputData()
{
    printf("%d\n", ans);
}
void move_cloud(int cnt)
{
    int d = cmd[cnt][0];
    int s = cmd[cnt][1] % N;

    int cpy_cloud[MAXN + 10][MAXN + 10];
    memcpy(cpy_cloud, cloud, sizeof(cloud));
    memset(cloud, 0, sizeof(cloud));
    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            if(cpy_cloud[r][c])
            {
                int nr = r + (dr[d] * s);
                int nc = c + (dc[d] * s);
                if(nr <= 0){
                    nr = N + nr;
                }
                else if(nr > N){
                    nr = nr - N;
                }
                if(nc <= 0){
                    nc = N + nc;
                }
                else if(nc > N){
                    nc = nc - N;
                }

                cloud[nr][nc] = 1;
                A[nr][nc]++;
            }   
        }
    }
}
void water_bug()
{
    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            if(cloud[r][c])
            {
                int count = 0;
                for (int i = 0; i < 4; i++)
                {
                    int nr = r + water_bug_dr[i];
                    int nc = c + water_bug_dc[i];

                    if(nr < 1 || nc < 1 || nr > N || nc > N) continue;

                    if(A[nr][nc] > 0) count++;
                }
                A[r][c] += count;
            }
        }
    }
}
void create_cloud()
{
    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            if(cloud[r][c]) {
                cloud[r][c] = 0;
                continue;
            }
            if(A[r][c] >= 2){
                cloud[r][c] = 1;
                A[r][c] -= 2;
            }
        }
    }
}
void sum_water()
{
    int count = 0;
    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            count += A[r][c];            
        }
    }

    ans = count;
}
void init()
{
    cloud[N-1][1] = 1;
    cloud[N-1][2] = 1;
    cloud[N][1] = 1;
    cloud[N][2] = 1;
}
void print_water()
{
    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            printf("%d ", A[r][c]);
        }
        printf("\n");
    }
}
void print_cloud()
{
    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            printf("%d ", cloud[r][c]);
        }
        printf("\n");
    }
    
}
void Solve()
{
    init();
    for (int i = 1; i <= M; i++)
    {
        move_cloud(i);
        water_bug();
        create_cloud();
    }
    sum_water();
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}

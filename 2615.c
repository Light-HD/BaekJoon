#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int ans;
int ansr, ansc;
int map[21][21];
int dr[] = {-1, 0, 1, 1};
int dc[] = {1, 1, 1, 0};

void InputData()
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
}
void OutputData()
{
    printf("%d\n",ans);
    if(ans){
        printf("%d %d\n", ansr, ansc);
    }
}

void DFS(int sr, int sc, int r, int c, int d, int color, int cnt)
{
    if(cnt >= 5){
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(map[nr][nc] == color) return;

        nr = sr - dr[d];
        nc = sc - dc[d];
        
        if(map[nr][nc] == color) return;

        ans = color;
        ansr = sr + 1;
        ansc = sc + 1;
        return;
    }

    int nr = r + dr[d];
    int nc = c + dc[d];
        
    if(nr < 0 || nc < 0 || nr >= 19 || nc >= 19) return;
    if(map[nr][nc] == color){
        DFS(sr, sc, nr, nc, d, color, cnt + 1);
    }

}
void Solve()
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if(map[i][j]){
                for (int k = 0; k < 4; k++)
                {
                    DFS(i, j, i, j, k, map[i][j], 1);
                }
            }
        }
    }
    
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}

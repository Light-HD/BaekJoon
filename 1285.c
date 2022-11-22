#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (30)
int ans = 0x7fffffff;
int N;
char map[MAXN][MAXN];
void InputData()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s",map[i]);
    }
}
void OutputData()
{
   printf("%d\n", ans);
}

void ChangeR(int idx){
    for (int i = 0; i < N; i++)
    {
        if(map[idx][i] == 'H'){
            map[idx][i] = 'T';
        }
        else{
            map[idx][i] = 'H';
        }
    }
}

void DFS(int idx)
{
    if(idx == N)
    {
        int totalt = 0;
        for (int c = 0; c < N; c++)
        {
            int hcnt = 0, tcnt = 0;
            for (int r = 0; r < N; r++)
            {
                if(map[r][c] == 'H') hcnt++;
                else if(map[r][c] == 'T') tcnt++;
            }
            if(hcnt > tcnt) totalt += tcnt;
            else totalt += hcnt;
        }
        ans = ans < totalt ? ans : totalt;
        return;
    }
    char cpymap[MAXN][MAXN];
    memcpy(cpymap, map, sizeof(map));
    //idx번째 행 뒤집기x
    DFS(idx + 1);
    memcpy(map, cpymap, sizeof(cpymap));
    //idx번째 행 뒤집기
    ChangeR(idx);
    DFS(idx + 1);
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

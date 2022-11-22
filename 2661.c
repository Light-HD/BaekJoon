#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (100)
int ans;
int N;
char num[MAXN];
int f;

void InputData()
{
    scanf("%d", &N);
}
int isPossible(int cnt){
    for (int i = 2; i <= cnt; i++)
    {
        int half = i / 2;
        for (int j = 1; j <= half; j++)
        {
            if(strncmp(num+i-(2*j)+1,num+i-j+1,j) == 0){
                return 0;
            }
        }
    }
    return 1;
}
void DFS(int cnt){
    if(cnt > N){
        f = 1;
        for (int j = 1; j <= N; j++)
        {
            printf("%c",num[j]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        if(f) return;
        num[cnt] = i + '0';
        if(isPossible(cnt)){
            DFS(cnt + 1);
        }
    }
    
}
void Solve()
{
    DFS(1);
}
int main()
{

    InputData();


    Solve();


    return 0;
}

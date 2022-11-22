#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (1000000)
int ans = 0x7fffffff;
int N;
int sol[MAXN];
int ori[MAXN];
int ori2[MAXN];
void InputData()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%1d",&ori[i]); 
    }
    memcpy(ori2, ori, sizeof(ori));
    for (int i = 0; i < N; i++)
    {
        scanf("%1d",&sol[i]); 
    }
}
void OutputData()
{
   printf("%d\n", ans);
}
void Change(int idx){
    if(idx != 0) ori[idx - 1] = !ori[idx - 1];
    ori[idx] = !ori[idx];
    if(idx != N-1) ori[idx + 1] = !ori[idx + 1];
}
void DFS(int idx, int push){
    // 마지막 스위치까지 다 결정한 시점에서
    if(idx == N)
    {
        //마지막 전구가 정답과 같아야 답이 존재했던 것
        if(ori[N-1] == sol[N-1]){
            ans = ans < push ? ans : push;
        }
        return;
    }
    // 이미 이전 전구가 같으면
    if(ori[idx - 1] == sol[idx - 1]){
        //누르지 않아야 함
        DFS(idx + 1, push);
    }
    else{
        Change(idx);
        DFS(idx + 1, push + 1);
    }
}
void Solve()
{
    // 첫 번째 누르는 경우
    Change(0);
    DFS(1, 1);
    // 첫 번째 누르지 않는 경우
    memcpy(ori, ori2, sizeof(ori2));
    DFS(1, 0);
    if(ans == 0x7fffffff){
        ans = -1;
    }
}
int main()
{
    InputData();

    Solve();

    OutputData();

    return 0;
}

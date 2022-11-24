#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int N, M;
int arr[10];
int sel[10];
int ck[10];
void InputData()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &sel[i]);
    }
}
// 같은 cnt에서 똑같은 것을 넣으면 안됨
void DFS(int cnt){
    int cntck[10002] = {0,};
    if(cnt >= M){
        for (int i = 0; i < M; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if(ck[i]) continue;
        if(cntck[sel[i]]) continue;
        ck[i] = 1;
        arr[cnt] = sel[i];
        cntck[sel[i]] = 1;
        DFS(cnt + 1);
        ck[i] = 0;

    }
    
}
int Compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}
void Solve()
{
    qsort(sel, N, sizeof(sel[0]), Compare);
    DFS(0);    
}
int main()
{

    InputData();

    Solve();

    return 0;
}

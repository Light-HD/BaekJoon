#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN 50
int ans;
int N, K;
int data[30];
int data_size;
int ck[150];
int arr;

void InputData()
{
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        char temp[30];
        scanf("%s", temp);
        int len = strlen(temp);
        for (int j = 0; j < len; j++)
        {
            data[i] |= (1 << (temp[j] - 'a'));
        }
    }
}
void OutputData()
{
   printf("%d\n", ans);
}
int Count(int mask){
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if((data[i] & ((1 << 26) - 1 - mask)) == 0){
            cnt++;
        }
    }
    return cnt;
}
int DFS(int idx, int k, int mask){
    if(k < 0) return 0;
    if (idx == 26) return Count(mask);
    int sol = 0;
    int t1 = DFS(idx + 1, k-1, mask | (1 << idx));
    if (sol < t1) sol = t1;
    if(idx != 'a'-'a' && idx != 'n'-'a' && idx != 't'-'a' && idx != 'i'-'a' && idx != 'c'-'a'){
        t1 = DFS(idx + 1, k, mask);
        if (sol < t1) sol = t1;
    }
    return sol;
    
}
void Solve()
{
    ans = DFS(0, K, 0);
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (5000)
int ans = 0x7fffffff;
int N, M;
int arr[MAXN + 10];
int max_high = 0;
void InputData()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        max_high += arr[i];
    }
}
void OutputData()
{
    printf("%d\n", ans);
}
int isPossible(int k){
    int cnt = 1;
    int minV = arr[0];
    int maxV = arr[0];

    for (int i = 1; i < N; i++)
    {
        minV = minV < arr[i] ? minV : arr[i];
        maxV = maxV > arr[i] ? maxV : arr[i];

        if((maxV - minV) > k){
            cnt++;
            minV = arr[i];
            maxV = arr[i];
        }
    }
    return cnt <= M;
}
void BS()
{
    int low = 0;
    int high = max_high;
    while(low <= high){
        int mid = (high + low) / 2;
        if(isPossible(mid)){
            ans = ans < mid ? ans : mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
}
void Solve()
{
    BS();   
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}

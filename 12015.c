#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (1000010)
int ans, max;
int N;
int A[MAXN];
int dp[MAXN];
int dpSize;

void InputData()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &A[i]);
    }
}
void OutputData()
{
   printf("%d\n", ans);
}
int BinarySearch(int low, int high, int k){
    int sol = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(dp[mid] > k){
           high = mid - 1;
        }
        else if(dp[mid] < k){
            sol = mid + 1;
            low = mid + 1;
        }
        else return mid;
    }
    return sol;
}
void Solve()
{

    dp[1] = A[1];
    dpSize = 1;

for (int i = 1; i <= N; i++)
{
    if(dp[dpSize] < A[i]){
        dp[++dpSize] = A[i];
    }
    else {
        int idx = BinarySearch(0, dpSize, A[i]);
        dp[idx] = A[i];
    }
}
ans = dpSize;

    
    
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}

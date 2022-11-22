#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (1000000)
long long ans;
int N, M;
long long lec[MAXN];
long long max;

void InputData()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &lec[i]);
        max += lec[i];
    }
}
void OutputData()
{
   printf("%lld\n", ans);
}
int isPossible(long long k){
    long long sum = 0;
    int cnt = 1;
    for (int i = 0; i < N; i++)
    {
        if(lec[i] > k) return 0;
        sum += lec[i];
        if(sum > k){
            sum = lec[i];
            cnt++;
            if(cnt > M) return 0;
        }
    }

    return 1;
}
void BS(){
    long long low = 1;
    long long high = max;
    while(low <= high){
        long long mid = (low + high) / 2;
        if(isPossible(mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
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

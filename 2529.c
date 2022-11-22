#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
int ans;
int N;
char sign[30];
int ck[12];
char small[12];
char big[12];
long long max, min = LLONG_MAX;
char chrmin[12];
void InputData()
{
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
    {
        scanf("%s", sign + i);
    }
}
void OutputData()
{
   printf("%lld\n", max);
   printf("%s\n", chrmin);
}
int isPossible(char arr[]){
    for (int i = 0; i <= N; i++)
    {
        int a = arr[i] - '0';
        int b = arr[i+1] - '0';

        if(sign[i] == '>'){
            if(a <= b) return 0;
        }
        else if(sign[i] == '<'){
            if(a >= b) return 0;
        }
    }
    return 1;
}
void Permutation(int cnt){
    if(cnt > N){
        if(isPossible(big)){
            long long bignum = atoll(big);
            max = max > bignum ? max : bignum;
        }
        if(isPossible(small)){
            long long smallnum = atoll(small);
            if(smallnum < min){
                min = smallnum;
                strcpy(chrmin, small);
                chrmin[N+1] = '\0';
            }
        }
        return;
    }

    for (int i = 0; i <= N; i++)
    {
        if(ck[i]) continue;
        ck[i] = 1;
        small[cnt] = i + '0';
        big[cnt] = 9 - i + '0';
        Permutation(cnt + 1);
        ck[i] = 0;
    }
    
}
void Solve()
{   
    Permutation(0);   
}
int main()
{

    InputData();

    Solve();

    OutputData();

    return 0;
}

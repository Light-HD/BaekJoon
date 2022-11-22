#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int ans;
int N, M;

void InputData()
{
    scanf("%d %d", &N, &M);
}
void OutputData()
{
   printf("%d\n", ans);
}

void Solve()
{
    if(N == 1){
        ans = 1;
        return;
    }
    if(N == 2){
        ans = (M - 1) / 2 + 1;
        ans = ans < 4 ? ans : 4;
        return;
    }
    else{
        if(M <= 4){
            ans = M;
            return;
        }
        else if (M == 5 || M == 6){
            ans = 4;
            return;
        }
        else {
            ans = M - 2;
            return;
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

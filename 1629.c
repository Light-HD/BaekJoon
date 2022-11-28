#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
ll ans;
int A, B, C;
void InputData()
{
    scanf("%d %d %d", &A, &B, &C);
}
void OutputData()
{
   printf("%lld\n", ans);
}

ll Calc(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b % 2 == 0){
        ll k = Calc(a, b/2) % C;
        return k * k % C;
    }
    else{
        return a * Calc(a, b-1) % C;
    }
}
void Solve()
{
    ans = Calc(A, B) % C;
}
int main()

{

    InputData();

    Solve();

    OutputData();

    return 0;
}

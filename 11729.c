#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN (1000000)
int ans;
int N;

void InputData()
{
    scanf("%d", &N);
}
void Move(int n, int x, int y){
    if (n == 0) return;
    Move(n-1, x, 6-x-y); // 6-x-y : x, y칸 말고 남은 칸
    printf("%d %d\n", x, y);
    Move(n-1, 6-x-y, y);
}
void Solve()
{
    printf("%d\n", (int)pow(2, N) - 1);
    Move(N, 1, 3);
}
int main()
{

    InputData();

    Solve();

    return 0;
}

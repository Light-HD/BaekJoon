#include <stdio.h>
int dp[11];  //dp
int partial_sum(int n) {
    if (n == 1) return 1;    //초기값 지정
    if (n == 2) return 2;
    if (n == 3) return 4;
    if (dp[n] != 0) return dp[n];  //dp 배열에 저장되어 있으면 그 값을 사용
    return dp[n] = partial_sum(n - 1) + partial_sum(n - 2) + partial_sum(n - 3);  // 점화식
}
int main() {
    int T, n;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) 
    {
        scanf("%d", &n);
        printf("%d\n", partial_sum(n));
    }
}
//

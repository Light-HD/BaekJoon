#include <stdio.h>
int dp[501][501];
int get_max(int a, int b) { return a > b ? a : b; }
int main() {

    int n, i, j, max = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) 
        for (j = 1; j <= i; j++) 
            scanf("%d", &dp[i][j]);     //입력 data 저장

    for (i = 2; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            if (j == 0) dp[i][j] = dp[i - 1][0] + dp[i][j];         //가장 왼쪽
            else if (j == i) dp[i][j] = dp[i - 1][j - 1] + dp[i][j];        // 가장 오른쪽
            else dp[i][j] = get_max(dp[i - 1][j - 1] + dp[i][j], dp[i - 1][j] + dp[i][j]);      //중간의 경우 두 경우를 비교해 큰 값을 저장

            max = get_max(max, dp[i][j]);       //가장 큰 값을 max에 저장
        }
    }
    printf("%d\n", max);
    return 0;
}
//

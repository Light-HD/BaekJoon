#include <stdio.h>
int dp[501][501];
int get_max(int a, int b) { return a > b ? a : b; }
int main() {

    int n, i, j, max = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) 
        for (j = 1; j <= i; j++) 
            scanf("%d", &dp[i][j]);     //�Է� data ����

    for (i = 2; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            if (j == 0) dp[i][j] = dp[i - 1][0] + dp[i][j];         //���� ����
            else if (j == i) dp[i][j] = dp[i - 1][j - 1] + dp[i][j];        // ���� ������
            else dp[i][j] = get_max(dp[i - 1][j - 1] + dp[i][j], dp[i - 1][j] + dp[i][j]);      //�߰��� ��� �� ��츦 ���� ū ���� ����

            max = get_max(max, dp[i][j]);       //���� ū ���� max�� ����
        }
    }
    printf("%d\n", max);
    return 0;
}
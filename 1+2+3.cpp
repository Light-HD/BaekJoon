#include <stdio.h>
int A[11];
int partial_sum(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    if (A[n] != 0) return A[n];
    return A[n] = partial_sum(n - 1) + partial_sum(n - 2) + partial_sum(n - 3);
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
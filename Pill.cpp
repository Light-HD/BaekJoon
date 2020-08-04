#include <stdio.h>
#include <math.h>

unsigned long long dp[31][31];

unsigned long long wh(int w,int h) {
	if (h == 0) {
		return wh(w - 1, h + 1);
	}
	if (w == 0) return 1;
	if (w == 1) {
		return dp[w][h] = w + h;
	}
	if (dp[w][h] != 0) return dp[w][h];

	return dp[w][h] = wh(w - 1,h + 1) + wh(w,h - 1);
}
int main() {
	int input;
	int w[1000];
	int h = 0;
	int i = 0;
	while (1) {
		scanf("%d", &input);
		if (input == 0) break;
		w[i] = input;
		i++;
	}
	for (int j = 0; j < i; j++) {
		printf("%llu\n", wh(w[j], h));
	}
}
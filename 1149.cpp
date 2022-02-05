#include <stdio.h>
int A[1000][3];
int B[1000][3];
int min(int a, int b) { return a < b ? a : b; }
int Min(int arr[], int n) {
	if (n == 0)	return min(arr[1], arr[2]);
	if (n == 1)	return min(arr[0], arr[2]);
	if (n == 2) return min(arr[0], arr[1]);
}
int* RGB(int T) {
	if (T == 1) return A[T - 1];
	if (B[T - 1][0] != 0) return B[T - 1];
	for (int i = 0; i < 3; i++) {
		B[T - 1][i] = A[T - 1][i] + Min(RGB(T - 1), i);
	}
	return B[T - 1];
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) 
		for (int j = 0; j < 3; j++) 
			scanf("%d", &A[i][j]);
	printf("%d", min(min(RGB(T)[0], RGB(T)[1]), RGB(T)[2]));
}
//

#include <stdio.h>
#include <math.h>

int sum=0;

int base_Z(int r, int c) {
	if (r == 0 && c == 0) return 0;
	if (r == 0 && c == 1) return 1;
	if (r == 1 && c == 0) return 2;
	if (r == 1 && c == 1) return 3;
}
void findP(int N,int r,int c) {
	int mid, rp = 0, cp = 0;
	mid = pow(2,N) / 2;
	if (r >= mid) {
		r -= mid;
		rp++;
	}
	mid = pow(2,N) / 2;
	if  (c >= mid) {
		c -= mid;
		cp++;
	}
	
	sum += pow(4, N - 1) * base_Z(rp, cp);
	if (r > 1 || c > 1) findP(N - 1, r, c);
	else sum += base_Z(r, c);
}
int main() {
	int N,r,c;
	scanf("%d %d %d", &N,&r,&c);
	findP(N, r, c);
	printf("%d", sum);
}
#include <stdio.h>
#include <string.h>

int stararray[2188][2188];
int N;

int star(int M, int k) {				//공백 함수
	int mid = (M / 3) + 1;			//공백 시작 지점
	int rept = M / 3;				//공백 정사각형 길이
	if (k == 0) return 1;			//k = 0 인 경우, 함수 빠져나옴
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i % M == mid && j % M == mid) {		//나머지 판단으로 공백 시작 지점 찾음
				for (int l = 0; l < rept; l++) {	//공백 지점으로부터 정사각형 길이만큼 반복
					for (int m = 0; m < rept; m++) { //가로 세로 모두 반복
						stararray[i + l][j + m] = 0; //공백 만들기
					}
				}
			}
		}
	}
	k--;		//낮은 수준으로 가기 위해 k 값 1 줄임
	star(M/3, k);	//한 단계 낮은 수준에서 공백 만들기 시행
}



int main() {
	int M, k = 0;
	scanf("%d", &N);
	M = N;
	while (M != 1) {		//N이 3의 몇 k승인지 판단
		k++;
		M = M / 3;
	}
	memset(stararray, -1, sizeof(stararray));	//stararray를 모두 -1로 초기화
	star(N,k);								//공백 함수
	for (int i = 1; i <= N; i++) {		//-1이면 *을 0이면 공백을 printf
		for (int j = 1; j <= N; j++) {
			if (stararray[i][j] == -1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}

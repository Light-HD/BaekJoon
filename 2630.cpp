#include <stdio.h>

int N;
int paper[129][129];
int white, blue;

void divide(int x, int y, int length) {				//나누어서 정사각형을 판단하는 함수
	int wc = 0, bc = 0;
	for (int i = x; i < x+length; i++) {			//x시작점에서 길이만큼
		for (int j = y; j < y+length; j++) {		//y시작점에서 길이만큼
			if (paper[i][j] == 0) wc++;		//0이면 wc ++
			else bc++;				//1이면 bc ++
		}
	}
	if (wc == length * length) white++;		//wc카운트 했던게 넓이만큼 있으면 0으로 꽉찬것이므로 white 갯수 증가
	else if (bc == length * length) blue++;		//bc카운트 했던게 넓이만큼 있으면 1로 꽉찬것이므로 blue 갯수 증가
	else {						//둘다 아니라면 4등분으로 나눔	
		divide(x, y, length / 2);
		divide(x + (length / 2),y, length / 2);
		divide(x, y + (length / 2), length / 2);
		divide(x + (length / 2), y + (length / 2), length / 2);
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &paper[i][j]);
		}
	}
	divide(0,0,N);
	printf("%d\n%d", white, blue);
}

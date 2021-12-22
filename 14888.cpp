#include <stdio.h>

int N;			//수의 갯수
int num[11];	//수 배열을 저장하는 배열
int op[4];		//연산자 갯수를 저장하는 배열
int max = -1000000000;	//-무한대
int min = 1000000000;	//+무한대

int cal(int a, int b, int op_type) {		//연산자 종류에 따라 계산
	if (op_type == 0) return a + b;
	else if (op_type == 1) return a - b;
	else if (op_type == 2) return a * b;
	else return a / b;
}

void dfs(int result, int order) {		//dfs
	if (order == N) {
		if (result > max) max = result;		//max값 비교 후 저장
		if (result < min) min = result;		//min값 비교 후 저장
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {					//연산자 다 썼는지 확인
			op[i]--;						//연산자를 뺀후 그 다음 dfs로 재귀
			dfs(cal(result, num[order], i), order + 1);
			op[i]++;						//다른 경우를 위해 다시 연산자 갯수 늘려줌
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < 4; i++){
		scanf("%d", &op[i]);
	}
	dfs(num[0], 1);
	printf("%d\n%d\n", max, min);
}

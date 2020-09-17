#include <stdio.h>

int N;			//���� ����
int num[11];	//�� �迭�� �����ϴ� �迭
int op[4];		//������ ������ �����ϴ� �迭
int max = -1000000000;	//-���Ѵ�
int min = 1000000000;	//+���Ѵ�

int cal(int a, int b, int op_type) {		//������ ������ ���� ���
	if (op_type == 0) return a + b;
	else if (op_type == 1) return a - b;
	else if (op_type == 2) return a * b;
	else return a / b;
}

void dfs(int result, int order) {		//dfs
	if (order == N) {
		if (result > max) max = result;		//max�� �� �� ����
		if (result < min) min = result;		//min�� �� �� ����
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {					//������ �� ����� Ȯ��
			op[i]--;						//�����ڸ� ���� �� ���� dfs�� ���
			dfs(cal(result, num[order], i), order + 1);
			op[i]++;						//�ٸ� ��츦 ���� �ٽ� ������ ���� �÷���
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
#include <stdio.h>
#define SIZE 16
#define INF 10000000  //������ ǥ���� ��
#define START 0    //������
#define END N-1    //������

int N; //�������� �������� ������ ��� ����
int W[SIZE][SIZE];  //��� ��� �迭
int dist[SIZE];  //start�������� �ּ� �Ÿ��� �����ϴ� �迭
int prenode[SIZE]; //������带 �����ϴ� �迭
bool visit[SIZE];  //�湮�ߴ��� ���� üũ
int stack[SIZE];
int top = -1;

int push(int input) {
	if (top >= (SIZE - 1)) return 0;
	stack[++top] = input;
}
int pop() {
	if (top == -1) return 0;
	return stack[top--];
}

int minindex() {     //�湮���� ���� ��� �� �ּ� ���� ���� index ��ȯ
	int min = INF, index = 0;
	for (int i = 0; i < N; i++) {
		if (dist[i] < min && !visit[i]) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(){     //���ͽ�Ʈ�� �˰���
	for (int i = 0; i < N; i++) {
		if (W[START][i] == 0 && i != START) {  //�������� ���� ��� ���� 0�� �ƴ� �������� ��
			dist[i] = INF;
			prenode[i] = INF;
		}
		else {								// ��ΰ� �����ϸ� �Ÿ����� ����
			dist[i] = W[START][i]; 
			prenode[i] = START;
		}
	}
	visit[START] = true;   //START ���� �湮�����Ƿ� �湮ǥ��
	for (int i = 0; i < N; i++) { 
		int current = minindex();   //�湮 ���� �� �� ���� �ּҰ��� ���� ���� ����
		visit[current] = true;      // ���������� �湮ǥ��
		for (int j = 0; j < N; j++) {
			if (!visit[j] && W[current][j] != 0) {    //�湮�� ���߰� �Ÿ����� 0�� �ƴϰ�
				if (dist[current] + W[current][j] < dist[j]) {   //����Ǿ� �ִ� �Ÿ������� �����ؼ� ���� �Ÿ����� �� �۴ٸ�
					dist[j] = dist[current] + W[current][j];     //�����ؼ� ���� �Ÿ��� �ּҰ����� ����
					prenode[j] = current;		//���� ��忡 ���� ���� ����(��� ǥ�ø� ����)
				}
			}
		}
	}
}
void route() {        //��� �����ϴ� �Լ� (��Ʈ��ŷ ���)
	int node = END;     //���������� �����ؼ� prenode�迭�� ����Ǿ� �ִ� ���� Ȱ���� ��θ� �����Ѵ�.
	push(node);         //���ÿ� ���������� �־ START��带 ���������� ������ �� pop�Ѵ�.
	while (1) {
		push(prenode[node]);
		node = prenode[node];
		if (node == START) break;
	}
	for (int i = top; i > -1; i--) printf("%d ", pop());
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &W[i][j]);    //��� ��� �Է�
		}
	}
	dijkstra();
	printf("\n"); printf("START���� �� �������� �ִ� �Ÿ� : ");
	for (int i = 0; i < N; i++) printf("%d ", dist[i]);
	printf("\nSTART���� END������ �ִ� �Ÿ� : %d\n", dist[N - 1]);
	printf("\nStart���� END���� �ִ� ��� : "); route();
}
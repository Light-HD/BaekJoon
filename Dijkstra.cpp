#include <stdio.h>
#define SIZE 16
#define INF 10000000  //무한을 표현한 값
#define START 0    //시작점
#define END N-1    //도착점

int N; //시작점과 도착점을 포함한 노드 갯수
int W[SIZE][SIZE];  //경로 비용 배열
int dist[SIZE];  //start에서부터 최소 거리를 저장하는 배열
int prenode[SIZE]; //이전노드를 저장하는 배열
bool visit[SIZE];  //방문했는지 여부 체크
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

int minindex() {     //방문하지 않은 노드 중 최소 값을 가진 index 반환
	int min = INF, index = 0;
	for (int i = 0; i < N; i++) {
		if (dist[i] < min && !visit[i]) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(){     //다익스트라 알고리즘
	for (int i = 0; i < N; i++) {
		if (W[START][i] == 0 && i != START) {  //존재하지 않은 경로 값을 0이 아닌 무한으로 함
			dist[i] = INF;
			prenode[i] = INF;
		}
		else {								// 경로가 존재하면 거리값을 저장
			dist[i] = W[START][i]; 
			prenode[i] = START;
		}
	}
	visit[START] = true;   //START 노드는 방문했으므로 방문표시
	for (int i = 0; i < N; i++) { 
		int current = minindex();   //방문 안한 곳 중 가장 최소값인 곳을 먼저 선택
		visit[current] = true;      // 선택했으면 방문표시
		for (int j = 0; j < N; j++) {
			if (!visit[j] && W[current][j] != 0) {    //방문도 안했고 거리값도 0이 아니고
				if (dist[current] + W[current][j] < dist[j]) {   //저장되어 있는 거리값보다 경유해서 가는 거리합이 더 작다면
					dist[j] = dist[current] + W[current][j];     //경유해서 가는 거리를 최소값으로 저장
					prenode[j] = current;		//이전 노드에 대한 정보 저장(경로 표시를 위함)
				}
			}
		}
	}
}
void route() {        //경로 추적하는 함수 (백트랙킹 사용)
	int node = END;     //도착지부터 시작해서 prenode배열에 저장되어 있는 값을 활용해 경로를 추적한다.
	push(node);         //스택에 마지막부터 넣어서 START노드를 넣을때까지 저장한 후 pop한다.
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
			scanf("%d", &W[i][j]);    //경로 비용 입력
		}
	}
	dijkstra();
	printf("\n"); printf("START에서 각 노드까지의 최단 거리 : ");
	for (int i = 0; i < N; i++) printf("%d ", dist[i]);
	printf("\nSTART에서 END까지의 최단 거리 : %d\n", dist[N - 1]);
	printf("\nStart에서 END까지 최단 경로 : "); route();
}
#include <stdio.h>
#include <string.h>

int N, W[16][16], dp[16][1 << 16];
int INF = 10000000;

int min(int a, int b) { return a < b ? a : b; }

int tsp(int x, int visit)
{
	if (dp[x][visit] > -1) return dp[x][visit];		//dp에 저장된 값이 있으면 그 값을 바로 반환
	if (visit == (1 << N) - 1)			//모든 노드를 다 방문했을 경우
	{
		if (W[x][0] != 0) return W[x][0];		//x에서 출발지까지의 길이 있다면 그 경로의 비용 반환
		return INF;								//길이 없으면 무한 반환
	}
	int res = INF;					//res를 무한으로 지정
	for (int i = 0; i < N; i++)
	{
		if (visit & (1 << i) || W[x][i] == 0) continue;		//visit(이진수)와(1<<i) 둘다 1이거나 x에서 i까지 길이 없다면 continue
		res = min(res, tsp(i, visit | (1 << i)) + W[x][i]);		//아니면 res 값을 현재 res 값과 x에서i까지의 경로 값 + tsp 다음꺼랑 비교해서 작은걸 선택
	}
	dp[x][visit] = res;			//res 값을 dp에 저장
	return res;					//res 값을 반환
}
int main()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf_s("%d", &W[i][j]);
	memset(dp, -1, sizeof(dp));			//dp 배열의 모든 값을 -1로 초기화
	printf("%d\n", tsp(0, 1));
	return 0;
}
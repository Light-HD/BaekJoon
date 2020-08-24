#include <stdio.h>
#include <string.h>

int N, W[16][16], dp[16][1 << 16];
int INF = 10000000;

int min(int a, int b) { return a < b ? a : b; }

int tsp(int x, int visit)
{
	if (dp[x][visit] > -1) return dp[x][visit];		//dp에 저장된 값이 있으면 그 값을 바로 반환
	if (visit == (1 << (N - 1)) - 1)			//모든 노드를 다 방문했을 경우
	{
		if (W[x][N - 1] != 0) return W[x][N - 1];		//x에서 END 지점까지 길이 있으면 그 길로 가고
		return INF;								//길이 없으면 무한 반환
	}
	int res = INF;					//res를 무한으로 지정
	for (int i = 0; i < N; i++)
	{
		if (visit & (1 << i) || W[x][i] == 0) continue;	//방문한곳이거나 길이 없는 경우면 패스
		res = min(res, tsp(i, visit | (1 << i)) + W[x][i]);	//방문안한곳이고 길이 있으면 거기까지의 거리 + tsp()값중 작은거를 선택
	}
	dp[x][visit] = res;
	return res;
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
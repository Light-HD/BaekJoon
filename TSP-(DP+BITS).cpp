#include <stdio.h>
#include <string.h>

int N, W[16][16], dp[16][1 << 16];
int INF = 10000000;

int min(int a, int b) { return a < b ? a : b; }

int tsp(int x, int visit)
{
	if (dp[x][visit] > -1) return dp[x][visit];		//dp�� ����� ���� ������ �� ���� �ٷ� ��ȯ
	if (visit == (1 << N) - 1)			//��� ��带 �� �湮���� ���
	{
		if (W[x][0] != 0) return W[x][0];		//x���� ����������� ���� �ִٸ� �� ����� ��� ��ȯ
		return INF;								//���� ������ ���� ��ȯ
	}
	int res = INF;					//res�� �������� ����
	for (int i = 0; i < N; i++)
	{
		if (visit & (1 << i) || W[x][i] == 0) continue;		//visit(������)��(1<<i) �Ѵ� 1�̰ų� x���� i���� ���� ���ٸ� continue
		res = min(res, tsp(i, visit | (1 << i)) + W[x][i]);		//�ƴϸ� res ���� ���� res ���� x����i������ ��� �� + tsp �������� ���ؼ� ������ ����
	}
	dp[x][visit] = res;			//res ���� dp�� ����
	return res;					//res ���� ��ȯ
}
int main()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf_s("%d", &W[i][j]);
	memset(dp, -1, sizeof(dp));			//dp �迭�� ��� ���� -1�� �ʱ�ȭ
	printf("%d\n", tsp(0, 1));
	return 0;
}
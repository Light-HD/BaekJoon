#include <stdio.h>
#include <string.h>
#include <math.h>

int N;
int synergy[21][21];
int start[11], link[11], check[21];
int min = 1000000000;
int Sum_synergy(int a, int b) {					//�� ���� �ó��� ���� ���ϴ� �Լ�
			
	return synergy[a][b] + synergy[b][a];
}
int synergy_gap() {					//�� ���� �ó��� ���� ���̸� ���ϴ� �Լ�
	int a = 0,b = 0;
	for (int i = 1; i <= N / 2; i++) {
		for (int j = i+1; j <= N / 2; j++) {
			a += Sum_synergy(start[i], start[j]);		//start���� �ó��� ��
			b += Sum_synergy(link[i], link[j]);			//link���� �ó��� ��
		}
	}
	return abs(a - b);		//�� ���� �ó��� ������ ���밪
}
void dfs(int member, int num_team) {			//start ���� �� ����� ���� ������ �Ű������� ����
	if (num_team == (N / 2) + 1) {				//�� ���� �Ϸ�Ǹ�
		int j = 1;					
		for (int i = 1; i <= N; i++) {			//
			if (check[i] == 0) {
				link[j] = i; j++;
			}
		}
		if (min > synergy_gap()) min = synergy_gap();		//�ó��� ���̰� ���� ���� ���� min�� ����
	}
	else
	{ 
		for (int i = member; i <= N; i++) {
			start[num_team] = i;			//start ���� ���ο� ��� ����
			check[i] = 1;					//���� ���ϸ� check
			dfs(i + 1, num_team + 1);		//�� ���� �����
			check[i] = 0;
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &synergy[i][j]);
		}
	}

	memset(start, -1, sizeof(start));			//start �迭 �ʱⰪ -1
	memset(link, -1, sizeof(link));				//link �迭 �ʱⰪ -1
	start[1] = 1; check[1] = 1;					//start������ ������ 1�� ����
	dfs(2, 2);									//2��°�� 2������ ����
	printf("%d\n",min);
}
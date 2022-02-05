#include <stdio.h>
#include <string.h>
#include <math.h>

int N;
int synergy[21][21];
int start[11], link[11], check[21];
int min = 1000000000;
int Sum_synergy(int a, int b) {					//두 명의 시너지 합을 구하는 함수
			
	return synergy[a][b] + synergy[b][a];
}
int synergy_gap() {					//두 팀의 시너지 합의 차이를 구하는 함수
	int a = 0,b = 0;
	for (int i = 1; i <= N / 2; i++) {
		for (int j = i+1; j <= N / 2; j++) {
			a += Sum_synergy(start[i], start[j]);		//start팀의 시너지 합
			b += Sum_synergy(link[i], link[j]);			//link팀의 시너지 합
		}
	}
	return abs(a - b);		//두 팀의 시너지 차이의 절대값
}
void dfs(int member, int num_team) {			//start 팀에 들어갈 멤버와 현재 팀수를 매개변수로 받음
	if (num_team == (N / 2) + 1) {				//start팀 구성 완료
		int j = 1;					
		for (int i = 1; i <= N; i++) {			//link 팀도 check배열이 0인 경우를 넣어서 구성 완료
			if (check[i] == 0) {
				link[j] = i; j++;
			}
		}
		if (min > synergy_gap()) min = synergy_gap();		//시너지 차이가 가장 적은 것을 min에 저장
	}
	else
	{ 
		for (int i = member; i <= N; i++) {
			start[num_team] = i;			//start 팀에 새로운 멤버 저장
			check[i] = 1;					//팀에 속하면 check
			dfs(i + 1, num_team + 1);		//그 다음 명수로
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

	memset(start, -1, sizeof(start));			//start 배열 초기값 -1
	memset(link, -1, sizeof(link));				//link 배열 초기값 -1
	start[1] = 1; check[1] = 1;					//start팀에는 무조건 1이 있음
	dfs(2, 2);									//2번째의 2번부터 시작
	printf("%d\n",min);
}
//

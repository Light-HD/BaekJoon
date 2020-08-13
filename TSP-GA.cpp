#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N;
int W[16][16], link[16][16], population[16][16];
int cost[16],fitness[16],chromosome[16];

int max(int arr[]) {
	int maxx = 0, maxxindex = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] > maxx) {
			maxx = arr[i];
			maxxindex = i;
		}
	}
	return maxx;
}
int maxindex(int arr[]) {
	int maxx = 0, maxxindex = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] > maxx) {
			maxx = arr[i];
			maxxindex = i;
		}
	}
	return maxxindex;
}

void Population() {   // 초기 경로들 집합 생성 ex) 0 1 2 3 // 1 0 3 2...
	int city,arrend;

	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			population[i][j] = -1;
			if (j == 0) {
				city = rand() % N;
				population[i][j] = city;
			}
			else population[i][j] = city;
			for (int l = 0; l < j; l++) {
				if (population[i][j] == population[i][l]) {
					j--;
					city = population[i][j];
					continue;
				}
			}
			for (int k = 0; k < N; k++) {
				if (link[city][k] == -1) {
					arrend = k;
					break;
				}
			}
			city = link[city][rand() % arrend];
		}
	}
}
void Cost() {

	for (int i = 0; i < N; i++) {
		cost[i] = 0;
		for (int j = 0; j < N; j++) {
			if (j == N - 1) {
				cost[i] += W[population[i][j]][population[i][0]];
			}
			else
				cost[i] += W[population[i][j]][population[i][j + 1]];
		}
	}
}
int fitnessSum() {
    int sum;

	sum = 0;
	for (int i = 0; i < N; i++) sum += fitness[i];
	return sum;
}
void Fitness() {
	int min = 1000000,maxx = 0,minindex = 0,maxindex = 0;
	Cost();
	for (int i = 0; i < N; i++) { //cost 최소값
		if (cost[i] != 0) {
			if (cost[i] < min) {
				min = cost[i];
				minindex = i;
			}
		}
	}
	maxx = max(cost);
	for (int i = 0; i < N; i++) { //cost 최대값
		if (cost[i] != 0) {
			if (cost[i] > maxx) {
				maxx = cost[i];
				maxindex = i;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (cost[i] != 0) {
			fitness[i] = (maxx - cost[i]) + ((maxx - min) / 3);
		}
	}
}
int SelectParent() {
	int point = rand() % fitnessSum();
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += fitness[i];
		if (point < sum) {
			return i;
		}
	}
}
void Crossover(int parent1, int parent2) {
	int city, arrend;
	int random;
	int next;
	random = rand() % 2;
	if (random == 0) chromosome[0] = population[parent1][0];
	else chromosome[0] = population[parent2][0];
	for (int i = 1; i < N; i++) {
		chromosome[i] = -1;
		for (int k = 0; k < i; k++) {
			if (chromosome[k] == chromosome[i]) {
				i--;
				continue;
			}
		for (int j = 0; j < N; j++) {
			if (link[chromosome[i-1]][j] == -1) {
				arrend = j;
				break;
			}
		}
		chromosome[i] = link[chromosome[i-1]][rand() % arrend];
		}
	}
}
int GA() {
	int parent1, parent2, count = 0;
	Population();
	Fitness();
	parent1 = SelectParent();
	parent2 = SelectParent();
	
	while (1) {
		if (max(fitness) > 2000) return cost[maxindex(fitness)];
		else { Population(); Fitness(); }
	
		if (count == 100) return cost[maxindex(fitness)];
		count++;
	}
	for (int i = 0; i < N; i++) {
		if (max(fitness) > 2000) return cost[maxindex(fitness)];
	}
	Crossover(parent1, parent2);
}
int main() {
	int k;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &W[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		k = 0;
		for (int j = 0; j < N; j++) {
			if (W[i][j] != 0) {
				link[i][k] = j;
				k++;
			}
		}
		link[i][k] = -1;
	}
	printf("최종 값 : %d", GA());
}
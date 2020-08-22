#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 32

int N;
int W[16][16], population[T][16];
int cost[T], chromosome[T], fitness[T];


int max(int arr[]) {
	int max = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}
int maxindex(int arr[]) {
	int max = 0, maxindex = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] > max) {
			maxindex = i;
		}
	}
	return maxindex;
}
int min(int arr[]) {
	int min = 1000000, minindex = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] < min) min = arr[i];
	}
	return min;
}
int minindex(int arr[]) {
	int min = 1000000, minindex = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] < min) {
			min = arr[i];
			minindex = i;
		}
	}
	return minindex;
}

void Population() {   // �ʱ� ��ε� ���� ���� ex) 0 1 2 3 // 1 0 3 2... (population �迭�� ����)
	int city, next;
	int num[16];
	srand((unsigned)time(NULL));
	for (int i = 0; i < T; i++) {
		for (int l = 0; l < N; l++) num[l] = l;
		for (int j = 0; j < N; j++) {
			city = rand() % (N - j);
			population[i][j] = num[city];
			for (int k = city; k < N; k++) num[k] = num[k + 1];
		}
	}
}
void Cost() {   //population�� �� ���(chromosome)�� �Ÿ��� ����ϴ� �Լ� (cost�迭�� ����)

	for (int i = 0; i < T; i++) {
		cost[i] = 0;
		for (int j = 0; j < N; j++) {
			if (j == N - 1) { // ������ ������ ���� ������ �������� ó�� ���������� �Ÿ� ���
				if (W[population[i][j]][population[i][0]] == 0) { cost[i] += 1000000; continue; }
				else  cost[i] += W[population[i][j]][population[i][0]];
			}
			else // ���� ���������� �Ÿ� ���
				if (W[population[i][j]][population[i][j + 1]] == 0) { cost[i] += 1000000; continue; }
				else
					cost[i] += W[population[i][j]][population[i][j + 1]];
		}
	}
}
int fitnessSum() {
	int sum;

	sum = 0;
	for (int i = 0; i < T; i++) sum += fitness[i];
	return sum;
}
void Fitness() {  // ���յ� �� �Լ�
	for (int i = 0; i < T; i++) {
		if (cost[i] != 0)
			fitness[i] = (1000 / cost[i]); // ���յ� = �Ÿ����� ���� * 1000
	}
}
int SelectParent() {
	int point = rand() % fitnessSum();
	int sum = 0;
	for (int i = 0; i < T; i++) {
		sum += fitness[i];
		if (point < sum) {
			return i;
		}
	}
}
void Crossover(int parent1, int parent2) {
	int point1, point2, a, b, temp, count = 0;
	point1 = N / 3; point2 = (2 * N) / 3;
	for (int k = count; k < 16; k += 2) {
		for (int i = 0; i < N; i++) {
			population[k][i] = population[parent1][i];
			population[k + 1][i] = population[parent2][i];
		}
		for (int i = point1; i < point2; i++) {
			for (int j = 0; j < N; j++) {
				if (population[k][i] == population[k + 1][j]) a = j;   //a = parent2���� parent1�� �߰��� ��ġ�ϴºκ�
				if (population[k + 1][i] == population[k][j]) b = j;  //b = parent1���� parent2�� �߰��� ��ġ�ϴºκ�
			}
			temp = population[k][i];                         // �߰����� ���� 
			population[k][i] = population[k + 1][i];
			population[k + 1][i] = temp;

			temp = population[k + 1][a];                   //������ a b ���� ���� ex) �߰����� ������ 2��5������ 5��2�� ����
			population[k + 1][a] = population[k][b];
			population[k][b] = temp;
		}
	}
}
void Mutation(int parent1, int parent2) {
	int count = 16, a, b, temp;
	srand((unsigned)time(NULL));
	for (int i = count; i < 32; i += 2) {
		a = N;
		b = rand() % (N - 1);
		for (int j = 0; j < N; j++) {
			population[i][j] = population[parent1][j];
			population[i + 1][j] = population[parent2][j];
		}
		temp = population[i][a];
		population[i][a] = population[i][b];
		population[i][b] = temp;

		temp = population[i + 1][a];
		population[i + 1][a] = population[i + 1][b];
		population[i + 1][b] = temp;
	}
}
int GA() {
	int parent1, parent2, count = 0;
	Population();
	Cost();
	Fitness();
	parent1 = SelectParent();
	parent2 = SelectParent();

	while (1) {
		Crossover(parent1, parent2);
		Mutation(parent1, parent2);
		Cost();
		Fitness();
		printf("���� ���� : %d, �ּڰ� : %d\n", count, cost[maxindex(fitness)]);

		if (count == 500) return cost[maxindex(fitness)];
		count++;
	}
}
int main() {
	srand((unsigned)time(NULL));
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &W[i][j]);
		}
	}
	printf("%d", GA());
}
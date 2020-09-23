#include <stdio.h>
#include <string.h>

int stararray[2188][2188];
int N;

int star(int M, int k) {				//���� �Լ�
	int mid = (M / 3) + 1;			//���� ���� ����
	int rept = M / 3;				//���� ���簢�� ����
	if (k == 0) return 1;			//k = 0 �� ���, �Լ� ��������
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i % M == mid && j % M == mid) {		//������ �Ǵ����� ���� ���� ���� ã��
				for (int l = 0; l < rept; l++) {	//���� �������κ��� ���簢�� ���̸�ŭ �ݺ�
					for (int m = 0; m < rept; m++) { //���� ���� ��� �ݺ�
						stararray[i + l][j + m] = 0; //���� �����
					}
				}
			}
		}
	}
	k--;		//���� �������� ���� ���� k �� 1 ����
	star(M/3, k);	//�� �ܰ� ���� ���ؿ��� ���� ����� ����
}



int main() {
	int M, k = 0;
	scanf("%d", &N);
	M = N;
	while (M != 1) {		//N�� 3�� �� k������ �Ǵ�
		k++;
		M = M / 3;
	}
	memset(stararray, -1, sizeof(stararray));	//stararray�� ��� -1�� �ʱ�ȭ
	star(N,k);								//���� �Լ�
	for (int i = 1; i <= N; i++) {		//-1�̸� *�� 0�̸� ������ printf
		for (int j = 1; j <= N; j++) {
			if (stararray[i][j] == -1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}
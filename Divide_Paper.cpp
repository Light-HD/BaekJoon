#include <stdio.h>

int N;
int paper[129][129];
int white, blue;

void divide(int x, int y, int length) {				//����� ���簢���� �Ǵ��ϴ� �Լ�
	int wc = 0, bc = 0;
	for (int i = x; i < x+length; i++) {			//x���������� ���̸�ŭ
		for (int j = y; j < y+length; j++) {		//y���������� ���̸�ŭ
			if (paper[i][j] == 0) wc++;				//0�̸� wc ++
			else bc++;								//1�̸� bc ++
		}
	}
	if (wc == length * length) white++;				//wcī��Ʈ �ߴ��� ���̸�ŭ ������ 0���� �������̹Ƿ� white ���� ����
	else if (bc == length * length) blue++;			//bcī��Ʈ �ߴ��� ���̸�ŭ ������ 1�� �������̹Ƿ� blue ���� ����
	else {											//�Ѵ� �ƴ϶�� 4������� ����	
		divide(x, y, length / 2);
		divide(x + (length / 2),y, length / 2);
		divide(x, y + (length / 2), length / 2);
		divide(x + (length / 2), y + (length / 2), length / 2);
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &paper[i][j]);
		}
	}
	divide(0,0,N);
	printf("%d\n%d", white, blue);
}
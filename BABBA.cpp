#include <stdio.h>
int main() {
	int k,temp,A=1,B=0;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		temp = A;	//������ A���� temp�� �ӽ�����
		A = B;		//A�� ������Ʈ(������ B)
		B += temp;	//B�� ������Ʈ(������ A+B)
	}
	printf("%d %d", A, B);
}
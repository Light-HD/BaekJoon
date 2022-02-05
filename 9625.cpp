#include <stdio.h>
int main() {
	int k,temp,A=1,B=0;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		temp = A;	//이전의 A값을 temp에 임시저장
		A = B;		//A값 업데이트(이전의 B)
		B += temp;	//B값 업데이트(이전의 A+B)
	}
	printf("%d %d", A, B);
}
//

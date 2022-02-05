import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] sw = new int[n];
		/* 스위치 입력 받기 */
		for (int i = 0; i < n; i++) {
			sw[i] = sc.nextInt();
		}
		int st = sc.nextInt();
		for (int i = 0; i < st; i++) {
			int g = sc.nextInt();
			int num = sc.nextInt();
			switch (g) {
			/* 남학생인 경우 */
			case 1:
				for (int j = 0; j < n; j++) {
					if ((j + 1) % num == 0) { // 받은 번호의 배수마다
						sw[j] = ~sw[j] & 0x1; // 비트 반전
					}
				}
				break;
			/* 여학생인 경우 */
			case 2:
				int start = num - 2;
				int end = num;
				boolean is = false;
				while (true) {
					if(start < 0) {
						start++;
						end--;
						break;
					}else if(end >= n) {
						end--;
						start++;
						break;
					}
					if(sw[start] == sw[end]) {
						start--;
						end++;
						is = true;
					}else {
						start++;
						end--;
						break;
					}
				}
				if(!is) {
					sw[num-1] = ~sw[num-1] & 0x1;
				}else {
					for(int j=start; j<=end; j++) {
						sw[j] = ~sw[j] & 0x1;
					}
				}
				break;
			}
		}
		int cnt = 0;
		for(int j=0; j<n; j++) {
			if(cnt == 20) {
				System.out.println();
				cnt = 0;
			}
			if(j == n-1) {
				System.out.println(sw[j]);
			}else {
				System.out.print(sw[j]+" ");
				cnt++;
			}
		}
	}
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int N, res, min;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		int[] balls = new int[N];
		// 입력
		for (int i = 0; i < N; i++) {
			balls[i] = Integer.parseInt(br.readLine());
		}
		min = Integer.MAX_VALUE;
		go(balls);
		System.out.println(min);
	}
	// 0~N까지 공 색 3가지 경우로 바꿔보기
	public static void go(int[] balls) {
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= 3; j++) {
				res = N;
				if(balls[i] == j) continue;
				int tmp = balls[i];
				balls[i] = j;
				check(balls);
				balls[i] = tmp;
				min = Math.min(min, res);
			}
		}
	}
	
	// 연속된 수 세기 만약 그 위 아래로 합이 또 4이상이 나오면 누적해서 계산
	public static void check(int[] balls) {
		int color = balls[N-1];
		int cnt = 1;
		// 밑에서부터 위로 올라가며 연속되는 색 체크하고 4개 이상이면 0으로 바꾸기
		for (int i = N-2; i >= 0; i--) {
			if(balls[i] == color) {
				cnt++;
			}else if(balls[i] != 0){
				// 공 색이 바꼈을 때 누적 cnt가 4이상이면 그 만큼 전체에서 삭제
				if(cnt >= 4) {
					res -= cnt;
					int up = i; // 그 위에 부터 다시 세주기
					int down = i+1+cnt; // 아래에서도 마찬가지로 세주기
					boolean flag = true; // 누적 4 이상이 나왔으면 계속 반복
					while(flag) {
						flag = false;
						// 경계 밖이면 종료
						if(up < 0 || down >= N) break;
						int upcolor = balls[up]; // 위쪽 색
						int downcolor = balls[down]; // 아래쪽 색
						int upcnt = 1;
						int downcnt = 1;
						int totalcnt = 0;
						// 위쪽 같은 색 세기
						while(true) {
							--up;
							if(up < 0 || balls[up] != upcolor) break;
							upcnt++;
						}
						// 아래쪽 같은 색 세기
						while(true) {
							down++;
							if(down >= N || balls[down] != downcolor) break;
							downcnt++;
						}
						// 위 아래 같은 색이면
						if(upcolor == downcolor) {
							totalcnt = upcnt + downcnt;
							// 4개 이상이면
							if(totalcnt >= 4) {
								res -= totalcnt;
								flag = true;
							}
						}else {
							// 위쪽 색 4개 이상이면
							if(upcnt >= 4) {
								res -= upcnt;
								flag = true;
							// 아래쪽 색 4개 이상이면
							}else if(downcnt >= 4) {
								res -= downcnt;
								flag = true;
							}
						}
					}
					
				}
				cnt = 1;
				color = balls[i];
			}
		}
	}
}

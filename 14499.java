import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	public static class Dice{
		private int r, c;
		private int top = 1, right = 3, front = 5;
		private int num[] = new int[7];
		

		public Dice(int r, int c) {
			this.r = r;
			this.c = c;
		}
		
	}
	public static final int E = 1, W = 2, N = 3, S = 4;
	public static int R, C, K, map[][], com[];
	public static int[] dr = {0, 0, 0, -1, 1};
	public static int[] dc = {0, 1, -1, 0, 0};
	public static Dice dice;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stn = new StringTokenizer(br.readLine());
		R = Integer.parseInt(stn.nextToken());
		C = Integer.parseInt(stn.nextToken());
		map = new int[R][C];
		
		int r = Integer.parseInt(stn.nextToken());
		int c = Integer.parseInt(stn.nextToken());
		K = Integer.parseInt(stn.nextToken());
		com = new int[K];
		dice = new Dice(r, c);
		
		// map 입력
		for (int i = 0; i < R; i++) {
			stn = new StringTokenizer(br.readLine());
			for (int j = 0; j < C; j++) {
				map[i][j] = Integer.parseInt(stn.nextToken());
			}
		}
		
		// 명령어 입력
		stn = new StringTokenizer(br.readLine());
		for (int i = 0; i < K; i++) {
			com[i] = Integer.parseInt(stn.nextToken());
		}
		
		// 각각의 명령어 수행
		for (int i = 0; i < K; i++) {
			int nr = dice.r + dr[com[i]]; // 다음 이동 위치
			int nc = dice.c + dc[com[i]];
			// 경계 조건
			if(nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
			
			// 주사위 이동
			dice.r = nr;
			dice.c = nc;
			
			// 주사위 각 값
			int top = dice.top;
			int right = dice.right;
			int front = dice.front;
			
			// 주사위 굴려서 전개도 맞춰주기
			switch (com[i]) {
			case E:
				dice.top = 7-right;
				dice.right = top;
				dice.front = front;
				break;
			
			case W:
				dice.top = right;
				dice.right = 7-top;
				dice.front = front;
				break;
				
			case N:
				dice.top = front;
				dice.right = right;
				dice.front = 7-top;
				break;
			
			case S:
				dice.top = 7-front;
				dice.right = right;
				dice.front = top;
				break;
			}
			
			// 현재 주사위 위 값 출력
			System.out.println(dice.num[dice.top]);
			
			// map 값 0이면
			if(map[nr][nc] == 0) {
				map[nr][nc] = dice.num[7-dice.top]; // 주사위에 있는 수 복사
			// 0이 아니면
			}else {
				dice.num[7-dice.top] = map[nr][nc]; // 맵값 주사위에 복사
				map[nr][nc] = 0; // 주사위 값 0으로 수정
			}
		}
	}
}

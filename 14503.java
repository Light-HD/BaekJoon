import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static class Robot {
		private int r,c,d;

		public Robot(int r, int c, int d) {
			this.r = r;
			this.c = c;
			this.d = d;
		}
	}
	
	public static final int N = 0, E = 1, S = 2, W = 3;
	public static int R, C, map[][];
	public static Robot cleaner;
	public static boolean ck[][];
	public static int[] dr = {-1,0,1,0};
	public static int[] dc = {0,1,0,-1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stn = new StringTokenizer(br.readLine());
		R = Integer.parseInt(stn.nextToken()); // 세로 크기
		C = Integer.parseInt(stn.nextToken()); // 가로 크기
		map = new int[R][C]; // 맵
		ck = new boolean[R][C]; // 방문 체크
		
		stn = new StringTokenizer(br.readLine());
		
		int r = Integer.parseInt(stn.nextToken());
		int c = Integer.parseInt(stn.nextToken());
		int d = Integer.parseInt(stn.nextToken());
		cleaner = new Robot(r, c, d); // 로봇 객체
		
		// 맵 입력
		for (r = 0; r < R; r++) {
			stn = new StringTokenizer(br.readLine());
			for (c = 0; c < C; c++) {
				map[r][c] = Integer.parseInt(stn.nextToken());
			}
		}
		
		work(); // 로봇 청소기 작동
		System.out.println(total());
		
		
	}
	
	public static void work() {
		clean(); // 청소
		int cnt = 0; // 회전 카운트
		while(true) { // 무한 루프
			rotate(); // 회전
			if(!move()) { // 갈수 없으면
				cnt++; // 회전 카운트 증가
			}else { // 갈 수 있으면 가고
				clean(); // 청소
				cnt = 0; // 카운트 초기화
			}
			if(cnt == 4) { // 4번 돌았을 때
				if(!back()) return; // 뒤로 못가면 종료 
				cnt = 0; // 뒤로 가고 카운트 초기화
			}
		}	
	}
	
	public static void clean() {
		ck[cleaner.r][cleaner.c] = true; // 방문체크에 표시
	}
	
	// 보는 방향으로 이동할 수 있으면 이동하고 안되면 false 리턴
	public static boolean move() {
		int r = cleaner.r;
		int c = cleaner.c;
		int d = cleaner.d;
		int nr = r + dr[d];
		int nc = c + dc[d];
		if(nr < 0 || nc < 0 || nr >= R || nc >= C) return false;
		if(ck[nr][nc] || map[nr][nc] == 1) return false;
		cleaner.r = nr;
		cleaner.c = nc;
		return true;
	}
	
	// 회전
	public static void rotate() {
		cleaner.d = cleaner.d - 1 == -1 ? 3 : cleaner.d -1;
	}
	
	// 뒤로 이동할 수 있으면 이동하고 안되면 false 리턴
	public static boolean back() {
		int r = cleaner.r;
		int c = cleaner.c;
		int d = cleaner.d;
		int nr = r - dr[d];
		int nc = c - dc[d];
		if(nr < 0 || nc < 0 || nr >= R || nc >= C) return false;
		if(map[nr][nc] == 1) return false;
		cleaner.r = nr;
		cleaner.c = nc;
		return true;
	}
	
	// 청소한 영역 개수 계산
	public static int total() {
		int sum = 0;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if(ck[r][c]) sum++;
			}
		}
		return sum;
	}
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static int R, C, T, map[][], cleaner;
	public static boolean ck[][];
	public static int[] tdr = {-1,0,1,0};
	public static int[] tdc = {0,1,0,-1};
	public static int[] bdr = {1,0,-1,0};
	public static int[] bdc = {0,1,0,-1};	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stn = new StringTokenizer(br.readLine());
		R = Integer.parseInt(stn.nextToken()); // 세로 크기
		C = Integer.parseInt(stn.nextToken()); // 가로 크기
		T = Integer.parseInt(stn.nextToken()); // 시간
		map = new int[R][C]; // 맵
		
		// 입력
		for (int i = 0; i < R; i++) {
			stn = new StringTokenizer(br.readLine());
			for (int j = 0; j < C; j++) {
				map[i][j] = Integer.parseInt(stn.nextToken());
			}
		}
		
		// 공기청정기 위치
		for (int i = 0; i < R; i++) {
			if(map[i][0] == -1) {
				cleaner = i;
				break;
			}
		}
		
		// 확산 작동 T초만큼 반복
		for (int i = 0; i < T; i++) {
			diffusion(); // 확산
			work(); // 공기청정기 작동
		}
		System.out.println(total());
	}
	
	public static void diffusion() {
		int sum[][] = new int[R][C]; // 임시로 확산될 거 저장할 공간
		// map 탐색
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				// 먼지가 있으면
				if(map[r][c] > 0) {
					int cnt = 0; // 확산된 방향 개수
					int divide = map[r][c] / 5; // 쪼개져야 하는 크기
					// 4방향 탐색
					for (int i = 0; i < 4; i++) {
						int nr = r + tdr[i];
						int nc = c + tdc[i];
						// 경계 조건
						if(nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
						// 공기청정기여도 패스
						if(map[nr][nc] == -1) continue;
						sum[nr][nc] += divide; // sum에 일단 누적 저장
						cnt++; // 확산된 방향 개수 증가
					}
					map[r][c] -= (divide * cnt); // 미세먼지 확산된 만큼 감소
				}
			}
		}
		
		// 확산되고 남은 미세먼지에 sum 값 합산 해주기
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				map[r][c] += sum[r][c];
			}
		}
	}
	
	// 공기 청정기 순환 반대로 탐색하며 한개씩 덮어씌우는 방식 (처음꺼는 자동 삭제됨)
	public static void work() {
		// 위쪽 순환
		int r = cleaner-1; // 시작점
		int c = 0;
		// 4방향 탐색
		for (int i = 0; i < 4; i++) {
			while(true) {
				int nr = r + tdr[i]; 
				int nc = c + tdc[i];
				// 경계 조건 (아래쪽 행 경계 주의)
				if(nr < 0 || nc < 0 || nr > cleaner || nc >= C) break;
				// 공기청정기면
				if(map[nr][nc] == -1) {
					map[r][c] = 0; // 현재 위치 0으로 수정
					break;
				}
				map[r][c] = map[nr][nc]; // 이전꺼 옮기기
				r = nr; // 현재 위치 수정
				c = nc;
			}
		}
		
		// 아래쪽 순환
		r = cleaner+2;
		c = 0;
		for (int i = 0; i < 4; i++) {
			while(true) {
				int nr = r + bdr[i]; 
				int nc = c + bdc[i];
				if(nr <= cleaner || nc < 0 || nr >= R || nc >= C) break;
				if(map[nr][nc] == -1) {
					map[r][c] = 0;
					break;
				}
				map[r][c] = map[nr][nc];
				r = nr;
				c = nc;
			}
		}
	}
	
	// 미세먼지 총량 계산
	public static int total() {
		int sum = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if(map[i][j] > 0) {
					sum += map[i][j];
				}
			}
		}
		return sum;
	}
}

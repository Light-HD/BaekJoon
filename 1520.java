import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	private static int R, C, map[][], dp[][];
	private static boolean visited[][];
	private static int[] dr = {1,-1,0,0};
	private static int[] dc = {0,0,1,-1};
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stn = null;
			stn = new StringTokenizer(br.readLine());
			R = Integer.parseInt(stn.nextToken()); // 행
			C = Integer.parseInt(stn.nextToken()); // 열
			map = new int[R][C];
			dp = new int[R][C];
			visited = new boolean[R][C];
			
			//맵 입력
			for (int i = 0; i < R; i++) {
				stn = new StringTokenizer(br.readLine());
				for (int j = 0; j < C; j++) {
					map[i][j] = Integer.parseInt(stn.nextToken());
				}
			}
		
			
			dfs(0, 0);
			System.out.println(dp[0][0]);
	}
	// 내리막으로 갈 수 있는 경로 다 가보기
	// dp : 3,3 -> 8,8 로 가는 경로가 4개인 것을 알았으면 그 값을 쓰면 됨 (4번 다시 반복할 필요 없음)
	private static int dfs(int r, int c) {
		// 종료 조건 (도착지 도착)
		if(r == R-1 && c == C-1) {
			return 1;
		}
		// dp에 값이 있으면 그 값 return
		if(dp[r][c] != 0) {
			return dp[r][c];
		}
		// 방문을 안했을 경우
		if(!visited[r][c]) {
			visited[r][c] = true; // 방문 체크
			// 4방향 탐색
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				// 경계 조건
				if(nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
				// 아직 방문 안했고 내리막이고 dp에 저장된 값이 없으면
				if(map[nr][nc] < map[r][c]) {
						dp[r][c] += dfs(nr, nc); // 이동
				}
			}	
		}
		return dp[r][c];
	}
}

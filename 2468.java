import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[] dc = {1, 0, -1, 0};
	static int[] dr = {0, 1, 0 ,-1};
	static int N, map[][];
	static boolean ck[][];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		int max = 0;
		int res = 0;
		// 입력
		for (int i = 0; i < N; i++) {
			StringTokenizer stn = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(stn.nextToken());
				max = Math.max(max, map[i][j]);
			}
		}
		
		//높이 0~max까지 가장 최대 영역(res) 구하기
		for (int k = 0; k < max; k++) {
			ck = new boolean[N][N];
			int tmp = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if(map[i][j] > k) ck[i][j] = true; 
				}
			}
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if(ck[i][j]) {
						tmp++; // 들어가면서 채우기
						dfs(i,j);			
					}
				}
			}
			res = Math.max(res, tmp);
		}
		System.out.println(res);
	}
	// 인접 영역 모두 다 색칠
	public static void dfs(int r, int c) {
		ck[r][c] = false;
		int nr, nc;
		for (int i = 0; i < 4; i++) {
			nr = r + dr[i];
			nc = c + dc[i];
			if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if(ck[nr][nc]) {
				dfs(nr, nc);
			}
		}
	}
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static int N, M, totalCnt, max, map[][], select[][];
	static ArrayList<int[]> safe = new ArrayList<>();
	static boolean[][] visited, ck;
	static int[] dc = {1,-1,0,0};
	static int[] dr = {0,0,1,-1};
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stn = new StringTokenizer(br.readLine());
		N = Integer.parseInt(stn.nextToken());
		M = Integer.parseInt(stn.nextToken());
		map = new int[N][M];
		visited = new boolean[N][M];
		select = new int[3][2];
		totalCnt = 0;
		
		// 입력
		for (int i = 0; i < N; i++) {
			stn = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(stn.nextToken());
				if(map[i][j] == 0) {
					safe.add(new int[] {i,j});
					totalCnt++;
				}
			}
		}
		com(0,0);
		System.out.println(max);
	}
	
	public static void com(int cnt, int start) {
		if(cnt == 3) {
			int[][] newMap = new int[N][M];
			copy(map, newMap);
			// 벽 3개 세우기
			for (int i = 0; i < 3; i++) {
				newMap[select[i][0]][select[i][1]] = 1;
			}
			// 바이러스 퍼뜨리기
			spread(newMap);
			
			int sum = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if(newMap[i][j] == 0) sum++;
				}
			}
			
			max = Math.max(max, sum);
			
			return;
		}
		for (int i = start; i < totalCnt; i++) {
			select[cnt] = safe.get(i);
			com(cnt+1, i+1);
		}
	}
	
	public static void spread(int[][] newMap) {
		ck = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if(!ck[i][j] && newMap[i][j] == 2) {
					dfs(i, j, newMap);
				}
			}
		}
	}
	
	public static void dfs(int r, int c, int[][] newMap) {
		ck[r][c] = true;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if(!ck[nr][nc] && newMap[nr][nc] == 0) {
				newMap[nr][nc] = 2;
				dfs(nr, nc, newMap);
			}
		}
	}
	
	public static void copy(int[][] map, int[][] newMap) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				newMap[i][j] = map[i][j];
			}
		}
	}
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	// 아기 상어 객체
	private static class Shark{
		private int r,c; // 상어 위치
		private int s; // 상어 사이즈
		private int cnt = 0; // 사이즈 업을 위한 먹은 개수

		public Shark(int r, int c, int s) {
			this.r = r;
			this.c = c;
			this.s = s;
		}
	}
	private static int N, map[][], min, res;
	private static boolean ck[][];
	private static Shark bs;
	private static Queue<int[]> list;
	private static int[] dr = {1,-1,0,0};
	private static int[] dc = {0,0,1,-1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine()); // 맵 크기	
		map = new int[N][N]; // 맵
		list = new LinkedList<>(); // 먹을 수 있는 후보 물고기 리스트
		ck = new boolean[N][N]; // 방문 체크
		
		// 맵 입력
		for (int r = 0; r < N; r++) {
			StringTokenizer stn = new StringTokenizer(br.readLine());
			for (int c = 0; c < N; c++) {
				map[r][c] = Integer.parseInt(stn.nextToken());
				if(map[r][c] == 9) {
					bs = new Shark(r, c, 2);
					map[r][c] = 0;
				}
			}
		}
		while(go());
		System.out.println(res);
	}
	
	private static boolean go() {
		seek(); // 후보 물고기 찾기 (list에 저장)
		int[] fish = new int[2]; // 유력한 물고기
		int dmin = Integer.MAX_VALUE; // 거리 가까운 거 찾기
		
		// 후보 물고기 중 가장 거리가 짧은 물고기 찾기
		int size = list.size(); // 후보 물고기 리스트 크기
		if(size == 0) return false; // 후보 물고기 없으면 끝
		for (int i = 0; i < size; i++) {
			int[] temp = list.poll(); // 후보 물고기 한마리 씩 비교
			int gr = temp[0];  // 후보 물고기의 행
			int gc = temp[1]; // 후보 물고기의 열
			min = Integer.MAX_VALUE;
			Queue<int[]> q = new LinkedList<>(); // bfs 큐
			q.add(new int[] {bs.r, bs.c}); // 시작점은 아기 상어 위치
			ck = new boolean[N][N]; // 방문체크 초기화
			bfs(0, gr, gc, q); // bfs로 후보 물고기까지의 가장 짧은 경로 탐색 (min에 저장)
			if(min == Integer.MAX_VALUE) continue; // 후보 물고기까지 도달못했으면 다음 물고기
			if(dmin > min) { // 후보 물고기들의 가장 짧은 경로 간 비교
				fish = temp; // 유력 물고기로 승격
				dmin = min;  // 거리 값 업데이트
			}else if(dmin == min) { // 유력 물고기와 거리가 같을 경우
				if(fish[0] > temp[0]) { // 위쪽 물고기 우선
					fish = temp;
				}else if(fish[0] == temp[0]) { // 행 값도 같을 경우
					if(fish[1] > temp[1]) { // 왼쪽 물고기 우선
						fish = temp;
					}
				}
			}
		}
		
		// 가장 짧은 물고기로 이동
		if(dmin == Integer.MAX_VALUE) return false; // 만약 dmin 업데이트 안됐으면 끝
		res += dmin; // 거리 값 더해주기
		// 아기상어 위치 바꿔주기
		bs.r = fish[0]; 
		bs.c = fish[1];
		bs.cnt++; // 아기 상어 먹은 먹이 수 증가
		// 아기 상어 먹은 먹이 수가 자신의 크기 와 같으면 크기 업 (최대 7까지 증가)
		if(bs.s < 7 && bs.cnt == bs.s) {
			bs.s++;
			bs.cnt = 0;
		}		
		map[bs.r][bs.c] = 0; // 먹은 먹이의 값 0으로 수정
		return true;
	}
	
	// 자신보다 크기가 작은 물고기 찾아서 list에 넣어 놓기
	private static void seek() {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if(map[r][c] != 0 && map[r][c] < bs.s) {
					list.offer(new int[] {r, c});
				}
			}
		}
	}
	
	// 작은 물고기들에 대해서 가장 짧은 경로로 이동하는 거리 계산
	private static void bfs(int cnt, int gr, int gc, Queue<int[]> q) {
		Queue<int[]> queue = new LinkedList<int[]>();
		int size = q.size();
		if(size == 0) return;
		for (int k = 0; k < size; k++) {
			int [] temp = q.poll();
			int r = temp[0];
			int c = temp[1];
			if(r == gr && c == gc) {
				min = Math.min(min, cnt);
				return;
			}
			//4방향 탐색
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
				if(ck[nr][nc] || map[nr][nc] > bs.s) continue;
				ck[nr][nc] = true;
				queue.offer(new int[] {nr,nc});
			}
			
		}
		bfs(cnt+1, gr, gc, queue);
	}
}

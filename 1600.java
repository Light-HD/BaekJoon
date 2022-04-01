import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int K, W, H, map[][];
	// 하, 우, 상, 좌
	static int[] mx = {0, 1, 0, -1};
	static int[] my = {1, 0, -1, 0};
	static int[] hx = {1, 2, 2, 1, -1, -2, -2, -1};
	static int[] hy = {2, 1, -1, -2, -2, -1, 1, 2};
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		K = Integer.parseInt(br.readLine());
		StringTokenizer stn = new StringTokenizer(br.readLine());
		W = Integer.parseInt(stn.nextToken());
		H = Integer.parseInt(stn.nextToken());
		map = new int[H+2][W+2];
		for (int i = 0; i < map.length; i++) {
			Arrays.fill(map[i], 1);
		}
		//map 입력
		for (int i = 1; i <= H ; i++) {
			stn = new StringTokenizer(br.readLine());
			for (int j = 1; j <= W; j++) {
				map[i][j] = Integer.parseInt(stn.nextToken());
			}
		}
		System.out.println(bfs(1, 1));
	}
	
	public static int bfs(int x, int y) {
		// 현재 위치에서 모든 이동 가능한 위치를 Point를 저장하는 Queue에 저장
		boolean visited[][][] = new boolean[H+2][W+2][K+1];
		Queue<Point> queue = new LinkedList<>();
		queue.add(new Point(x, y, 0, 0));
		visited[y][x][0] = true;
		
		while(!queue.isEmpty()) {
			Point p = queue.poll();
			// 도착지점이면
			if(p.x == W && p.y == H) {
				return p.cnt;
			}
			// 원숭이 이동 경우 
			for (int j = 0; j < 4; j++) {
				int ny = p.y+my[j];
				int nx = p.x+mx[j];
				if(!visited[ny][nx][p.a] && map[ny][nx] == 0) {
					visited[ny][nx][p.a] = true;
					queue.offer(new Point(nx, ny, p.a, p.cnt+1));
				}
			}
			// 말 이동 경우 
			if(p.a < K) {
				for (int j = 0; j < 8; j++) {
					int ny = p.y+hy[j];
					int nx = p.x+hx[j];
					if(nx<1 || nx>W || ny<1 || ny>H) continue;
					if(!visited[ny][nx][p.a+1] && map[ny][nx] == 0) {
						visited[ny][nx][p.a+1] = true;
						queue.offer(new Point(nx, ny, p.a+1, p.cnt+1));
					}
				}
			}
		}
		return -1;
	}
	
	public static class Point {
		private int x, y, a, cnt;

		public Point(int x, int y, int a, int cnt) {
			this.x = x;
			this.y = y;
			this.a = a;
			this.cnt = cnt;
		}
	}
}


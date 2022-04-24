import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static class Point{
		private int x;
		private int y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}
		
		
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stn = null;
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			int n = Integer.parseInt(br.readLine());
			int size = n+2;
			Point[] p = new Point[size];
			
			// 입력
			for (int i = 0; i < size; i++) {
				stn = new StringTokenizer(br.readLine());
				p[i] = new Point(Integer.parseInt(stn.nextToken()), Integer.parseInt(stn.nextToken()));
			}
			
			if(distance(p[0], p[size-1]) <= 1000) {
				System.out.println("happy");
			}else {
				boolean[][] map = new boolean[size][size];
				
				// 갈 수 있는 거 체크 하기
				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						if(i == j) continue;
						if(distance(p[i], p[j]) <= 1000) {
							map[i][j] = true;
						}
					}
				}
				
				// 체크 된 것을 기반으로 플루이드 와샬로 목적지 갈 수 있는지 체크
				for (int k = 0; k < size; k++) {
					for (int i = 0; i < size; i++) {
						if(i == k) continue;
						for (int j = 0; j < size; j++) {
							if(i == j || k == j) continue;
							if(map[i][k] && map[k][j]) {
								map[i][j] = true;
							}
						}
					}
				}
				
				if(map[0][n+1]) {
					System.out.println("happy");
				}else {
					System.out.println("sad");
				}
			}
		}
	}
	
	private static int distance(Point a, Point b) {
		return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
	}
}

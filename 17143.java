import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	public static class Shark implements Comparable<Shark>{
		private int r,c,s,d,z;
		
		public Shark(int r, int c, int s, int d, int z) {
			this.r = r;
			this.c = c;
			this.s = s;
			this.d = d;
			this.z = z;
		}

		@Override
		public int compareTo(Shark o) {
			// TODO Auto-generated method stub
			return o.z - this.z;
		}
		
	}
	
	public static int R,C,M,res;
	public static Shark[][] map;
	public static ArrayList<Shark> sList;
	public static int[] dr = {0, -1, 1, 0, 0};
	public static int[] dc = {0, 0, 0, 1, -1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stn = new StringTokenizer(br.readLine());
		R = Integer.parseInt(stn.nextToken());
		C = Integer.parseInt(stn.nextToken());
		M = Integer.parseInt(stn.nextToken());
		map = new Shark[R+1][C+1];
		res = 0;
		sList = new ArrayList<>();
		
		for (int i = 0; i < M; i++) {
			stn = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(stn.nextToken());
			int c = Integer.parseInt(stn.nextToken());
			int s = Integer.parseInt(stn.nextToken());
			int d = Integer.parseInt(stn.nextToken());
			int z = Integer.parseInt(stn.nextToken());
			map[r][c] = new Shark(r, c, s, d, z);
			sList.add(map[r][c]);
		}
		
		// 낚시왕 1칸씩 이동
		for (int c = 1; c <= C; c++) {
			for (int r = 1; r <= R; r++) {
				// 상어가 있으면
				if(map[r][c] != null) {
					Shark s = map[r][c];
					res += s.z; // 상어 크기 누적
					for (int i = 0; i < sList.size(); i++) {
						if(s == sList.get(i)) {
							sList.get(i).z = 0; // 상어 삭제
						}
					}
					map[r][c] = null; // 상어 삭제
					break;
				}
			}
			move();
		}
		
		System.out.println(res);
	}
	public static void move() {
		int size = sList.size();
		Collections.sort(sList); // 큰 상어부터 자리 차지
		Shark[][] newMap = new Shark[R+1][C+1];
		for (int i = 0; i < size; i++) {
			Shark s = sList.get(i);
			if(s.z == 0) continue;
			int moveCnt = 0;
			if(s.d < 3) {
				moveCnt = s.s % ((R-1)*2);
			}else {
				moveCnt = s.s % ((C-1)*2);
			}
			
			int nr = 0, nc = 0;
			for (int j = 0; j < moveCnt; j++) {
				nr = s.r + dr[s.d];
				nc = s.c + dc[s.d];
				
				// 상하이동
				if(s.d < 3) {
					// 현재 위치가 경계 밖이면
					if(nr < 1 || nr > R) {
						// 방향 바꾸고
						if(s.d % 2 == 0) {
							s.d--;
						}else {
							s.d++;
						}
						// 원래 있던 곳에서 다시 이동
						nr = s.r + dr[s.d];
						nc = s.c + dc[s.d];
					}
				// 좌우이동
				}else {
					if(nc < 1 || nc > C) {
						if(s.d % 2 == 0) {
							s.d--;
						}else {
							s.d++;
						}
						nr = s.r + dr[s.d];
						nc = s.c + dc[s.d];
					}
				}
				s.r = nr;
				s.c = nc;
			}
			if(newMap[s.r][s.c] == null) {
				newMap[s.r][s.c] = s;
			}else {
				s.z = 0; // 이미 상어가 있으면 죽음
			}
		}
		map = newMap;
	}
}

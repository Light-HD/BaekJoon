import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	private static class Point{
		private int r, c;
		public Point(int r, int c) {
			this.r = r;
			this.c = c;
		}
		
		@Override
		public String toString() {
			return "Point [r=" + r + ", c=" + c + "]";
		}
		
		
	}
	static int res[][], totalCnt;
	static boolean flag, ck[][][];
	static ArrayList<Point> pList = new ArrayList<>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// 스도쿠 입력
		res = new int[9][9];
		for (int r = 0; r < 9; r++) {
			String[] line = br.readLine().split("");
			for (int c = 0; c < 9; c++) {
				res[r][c] = Integer.parseInt(line[c]);
				if(res[r][c] == 0) {
					pList.add(new Point(r,c));
					++totalCnt;
				}
			}
		}
		go(res, 0);
		
		// 출력
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				System.out.print(res[i][j]);
			}
			System.out.println();
		}
	}
	
	// pList에 있는 점들의 가능성 있는 번호를 매겨보기
	private static void go(int[][] map, int index) {
		if(flag) return;
		// 종료 조건
		if(index == totalCnt) {
			copy(map, res);
			flag = true;
			return;
		}
		
		// pList에서 한개씩 꺼내서 가능성 있는 번호 후보 찾기 없으면 돌아오기
		int[][] newMap = new int[9][9];
		Point p = pList.get(index);
		ArrayList<Integer> list = availList(map, p);
		if(list.size() == 0) return; // 후보 숫자가 없으면 잘못된 스도쿠이므로 돌아감
		copy(map, newMap); // 기존 스도쿠 백업
		// 후보 숫자들 하나씩 넣어보기
		for (int i = 0; i < list.size(); i++) {
			newMap[p.r][p.c] = list.get(i);
			go(newMap, index+1);
			copy(map, newMap);
		}
	}
	private static ArrayList<Integer> availList(int[][] map, Point p) {
		int r = p.r;
		int c = p.c;
		boolean[] ck = new boolean[10];
		// 행에 있는 수 체크
		for (int i = 0; i < 9; i++) {
			if(map[r][i] != 0) {
				ck[map[r][i]] = true;
			}
		}
		// 열 점검
		for (int i = 0; i < 9; i++) {
			if(map[i][c] != 0) {
				ck[map[i][c]] = true;
			}
		}
		// 사각형 점검
		int str = r/3*3;
		int stc = c/3*3;
		for (int i = 0; i < 9; i++) {
			if(map[str+(i/3)][stc+(i%3)] != 0) {
				ck[map[str+(i/3)][stc+(i%3)]] = true;
			}
		}
		
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = 1; i <= 9; i++) {
			if(!ck[i]) {
				list.add(i);
			}
		}
		return list;
	}
	private static void copy(int[][] map, int[][] newMap) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				newMap[i][j] = map[i][j];
			}
		}
	}
}

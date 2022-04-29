import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	public static int N, map[][], p[], min;
	public static boolean ck[];
	public static ArrayList<Integer>[] lists;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stn = null;
		N = Integer.parseInt(br.readLine()); // 구역 수
		ck = new boolean[N+1]; // A = true, B = false;
		p = new int[N+1]; // 구역  인원 수
		lists = new ArrayList[N+1]; // lists[0] : 0번 구역이랑 연결되어 있는 구역
		
		// 구역 인원 수 입력
		stn = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			p[i] = Integer.parseInt(stn.nextToken());
			lists[i] = new ArrayList<Integer>();
		}
		
		// 연결 관계 입력
		for (int i = 1; i <= N; i++) {
			stn = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(stn.nextToken());
			for (int j = 0; j < n; j++) {
				lists[i].add(Integer.parseInt(stn.nextToken()));				
			}
		}
		
		min = Integer.MAX_VALUE; // min 초기화
		subSet(1); // 부분 집합
		System.out.println(min == Integer.MAX_VALUE ? -1 : min);
	}
	
	public static void subSet(int cnt) {
		if(cnt == N+1) {
			if(isConnect(true) && isConnect(false)) {
				int res = dif();
				min = Math.min(min, res);
			}
			return;
		}
		
		ck[cnt] = true;
		subSet(cnt+1);
		ck[cnt] = false;
		subSet(cnt+1);
	}
	
	// 그래프 연결관계 확인
	public static boolean isConnect(boolean op) {
		Queue<Integer> q = new LinkedList<>();
		boolean used[] = new boolean[N+1];
		
		// 해당 된 선거구의 구역 수 세기
		int cnt = 0;
		for(int i = 1; i <= N; i++) {
			if(ck[i]==op) {
				cnt++;
				// 초기 값 한개(포함된 구역) 넣어 놓기
				if(q.isEmpty()) { 
					q.offer(i);
					used[i] = true;
				}
			}
		}
		
		// BFS 풀이
		int real=0;
		while(!q.isEmpty()) {
			int cur = q.poll(); // 구역에 포함된 한개 구역 꺼내기
			real++;
			
			// 그 구역에 연결된 간선개수만큼 반복
			for(int i = 0; i < lists[cur].size(); i++) {
				int next = lists[cur].get(i); // 연결된 것 중 한개 선택
				// 그 노드 사용한적 없고 그 구역도 같은 선거구이면
				if(!used[next] && ck[next]==op) {
					q.offer(next); // 큐에 넣기
					used[next] = true; // 사용체크
				}
			}
		}
		
		// 선거구 개수랑 연결된 구역 수랑 같으면 true 다르면 false
		return cnt == real;
	}
	
	// 구역에 포함된 인원 수 세고 차이 값 구하기
	public static int dif() {
		int a = 0;
		int b = 0;
		for (int i = 1; i <= N; i++) {
			if(ck[i]) {
				a += p[i];
			}else {
				b += p[i];
			}
		}
		
		return Math.abs(a-b);
	}
}

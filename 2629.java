import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static int chu[],max,N;
	private static boolean dp[][];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine()); // 추의 개수		
		chu = new int[N+1]; // 추 무게 배열
		StringTokenizer stn = new StringTokenizer(br.readLine());
		
		// 추 무게 입력 받기
		for (int i = 0; i < N; i++) {
			chu[i] = Integer.parseInt(stn.nextToken());
		}

		int M = Integer.parseInt(br.readLine()); // 구슬 개수
		int[] gu = new int[M]; // 구슬 무게 배열

		// 구슬 무게 입력 받기
		max = 0;
		stn = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) {
			gu[i] = Integer.parseInt(stn.nextToken());
			max = Math.max(max, gu[i]);
		}

		dp = new boolean[N+1][40001];
		
		dfs(0, 0);
		
		for (int i = 0; i < gu.length; i++) {
			boolean flag = false;
			for (int j = 0; j < chu.length; j++) {
				if(dp[j][gu[i]]) {
					flag = true;
					break;
				}
			}
			System.out.print(flag ? "Y " : "N ");
		}
	}

	
	private static void dfs(int i, int w) {
		if(i > N || dp[i][w]) return;
		dp[i][w] = true;
		dfs(i+1, w + chu[i]);
		dfs(i+1, Math.abs(w-chu[i]));
		dfs(i+1, w);
	}
	
}

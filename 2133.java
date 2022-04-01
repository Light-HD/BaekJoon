import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] dp = N < 5 ? new int[5] : new int[N+1];
		dp[2] = 3;
		if(N >= 4 && N % 2 == 0) {
			// f(n) = f(n-2) * f(2) + (f(n-4) * 2 + f(n-6) * 2) + 2
			for (int i = 4; i < dp.length; i+=2) {
				dp[i] = dp[i-2] * dp[2];
				for (int j = i-4; j >= 0; j-=2) {
					dp[i] += dp[j] * 2;
				}
				dp[i] += 2;
			}
		}
		System.out.println(dp[N]);
	}
}

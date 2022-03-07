import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		boolean[] prime = new boolean[1001];
        prime[0] = prime[1] = true;
        for(int i=2; i*i<prime.length; i++){
        	// prime[i]가 소수라면
            if(!prime[i]){
            	// prime[j] 소수가 아닌 표시
            	for(int j=i*i; j<prime.length; j+=i) prime[j] = true;                
            }        
        }    
		int N = Integer.parseInt(br.readLine());
		StringTokenizer stn = new StringTokenizer(br.readLine());
		int res = 0;
		for (int i = 0; i < N; i++) {
			int temp = Integer.parseInt(stn.nextToken());
			if(!prime[temp]) {
				res++;
			}
		}
		System.out.println(res);
	}
}

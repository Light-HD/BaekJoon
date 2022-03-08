import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] A = new int[N];
		StringTokenizer stn = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			A[i] = Integer.parseInt(stn.nextToken());
		}
		int M = Integer.parseInt(br.readLine());
		stn = new StringTokenizer(br.readLine());
		Arrays.sort(A);
		for (int i = 0; i < M; i++) {
			int start = 0;
			int end = N-1;
			int temp = Integer.parseInt(stn.nextToken());
			while(true) {
				int idx = (start+end)/2;
				// 찾은 경우
				if(A[idx] == temp) {
					System.out.println(1);
					break;
				// 없을 경우
				}else if(start > end){
					System.out.println(0);
					break;
				}
				// 찾는 값이 더 클 경우 (오른쪽에 있는 것이므로)
				else if(A[idx] < temp) {
 					 start = idx+1;
				// 찾는 값이 더 작을 경우 (왼쪽에 있는 것이므로)
				}else if(A[idx] > temp) {
					end = idx-1;
				}
			}
		}
	}
}

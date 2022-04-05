import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	static int N, d, k, c, max, cnt, list[], res;
	static LinkedList<Integer> arr;
	static int ck[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stn = new StringTokenizer(br.readLine());
		N = Integer.parseInt(stn.nextToken());
		d = Integer.parseInt(stn.nextToken());
		k = Integer.parseInt(stn.nextToken());
		c = Integer.parseInt(stn.nextToken());
		list = new int[N];
		arr = new LinkedList<>();
		ck = new int[3001];
		max = 0;
		
		// 회전 초밥 입력
		for (int i = 0; i < N; i++) {
			list[i] = Integer.parseInt(br.readLine());
		}
		
		// 쿠폰 초밥은 항상 1개 있음
		res = 1;
		ck[c] = 1;
		
		// 첫번째 초밥 조합 k개 뽑기
		for (int i = 0; i < k; i++) {
			arr.add(list[i]);
			if(ck[list[i]] == 0) { // 종류가 다르면
				res++; // 종류 값 증가
			}
			// 해당 초밥 번호 개수 세기
			ck[list[i]]++;
		}
		
		cnt = k;
		for (int i = 0; i < N-1; i++) {
			// 종류 최대 값 비교
			max = Math.max(max, res);
			if(max == d) break; // 이미 최대 종류면 반복 종료
			// 다음 초밥
			int tmp = arr.removeFirst(); // 가장 앞에 것을 빼고
			ck[tmp]--;
			if(ck[tmp] == 0) res--; // 1개뿐이었던 초밥이 빠졌으면 종류 값 감소
			
			tmp = list[cnt % N];
			if(ck[tmp] == 0) res++; // 없던 초밥 추가되었으면 종류 값 증가
			arr.addLast(tmp); // 그 다음 것을 젤 뒤에 추가
			ck[tmp]++;
			
			cnt++;
		}
		System.out.println(max);
	}
}

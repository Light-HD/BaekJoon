import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] stick = sc.next().toCharArray();
		int floor = 0;
		int cnt = 0;
		for(int i=0; i<stick.length; i++) {
			if(stick[i] == '(' && stick[i+1] == '(') {
				floor++;
			}else if(stick[i] == '(' && stick[i+1] == ')') {
				cnt += floor;
			}else if(i+1 != stick.length && stick[i] == ')' && stick[i+1] == ')') {
				cnt += 1;
				floor--;
			}
		}
		System.out.println(cnt);
	}
}

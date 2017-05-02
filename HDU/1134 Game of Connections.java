import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	static final int N = 111;
	static boolean[] has = new boolean[N];
	static BigInteger[] c = new BigInteger[N];
	
	static BigInteger dfs(int n){
		if(n <= 1) return BigInteger.ONE;
		if(has[n]) return c[n];
		has[n] = true;
		c[n] = BigInteger.ZERO;
		for(int i = 0; i < n; i++) c[n] = c[n].add(dfs(i).multiply(dfs(n - 1 - i)));
		return c[n];
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n;
		Scanner in = new Scanner(System.in);
		while(in.hasNextInt()){
			n = in.nextInt();
			if(n < 0) break;
			System.out.println(dfs(n));
		}
	}
}

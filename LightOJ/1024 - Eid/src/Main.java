import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String arg[]){
		Scanner in = new Scanner(System.in);
		int T, n;
		BigInteger a, b;
		T = in.nextInt();
		for(int cas = 1; cas <= T; cas ++){
			n = in.nextInt();
			a = BigInteger.ONE;
			for(int i = 0; i < n; i ++){
				b = in.nextBigInteger();
				a = a.multiply(b).divide(a.gcd(b));
			}
			System.out.println("Case " + cas + ": " + a);
			System.gc();
		}
	}
}

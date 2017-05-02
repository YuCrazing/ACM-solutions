import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	static final int N = 202;
	static BigInteger[] fac = new BigInteger[N];

	static void init() {
		fac[0] = BigInteger.ONE;
		for (int i = 1; i < N; i++)
			fac[i] = BigInteger.valueOf(i).multiply(fac[i - 1]);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		init();
		int n;
		Scanner in = new Scanner(System.in);
		while (in.hasNextInt()) {
			n = in.nextInt();
			System.out.println(fac[2 * n].divide((fac[n].multiply(fac[n + 1]))));
		}
	}

}

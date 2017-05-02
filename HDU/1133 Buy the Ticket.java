import java.math.BigInteger;
import java.util.Scanner;

// (C(n + m, n) - C(n + m, n - 1)) * A(n, n) * A(m, m) = (n + m)! * (m + 1 - n) / (m + 1)

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
		int n, m, ca = 0;
		Scanner in = new Scanner(System.in);
		while (in.hasNextInt()) {
			ca++;
			m = in.nextInt();
			n = in.nextInt();
			if (n == 0 && m == 0)
				break;
			BigInteger ans = BigInteger.ZERO;
			if(n <= m) ans = fac[n + m].multiply(BigInteger.valueOf(m + 1 - n)).divide(BigInteger.valueOf(m + 1));
			System.out.println("Test #" + ca + ":");
			System.out.println(ans);
		}
	}

}

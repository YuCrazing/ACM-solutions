import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static public void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T;
		BigInteger a, b;
		T = in.nextInt();
		for(int cas = 1; cas <= T; cas ++){
			a = in.nextBigInteger();
			b = in.nextBigInteger();
			b = b.abs();
			System.out.print("Case " + cas + ": ");
			if(a.mod(b) == BigInteger.ZERO) System.out.println("divisible");
			else System.out.println("not divisible");
		}
	}
}

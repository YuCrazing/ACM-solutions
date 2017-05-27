import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {

	static int k;
	static int digs;
	static BigDecimal x;
	static BigDecimal eps;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			x = in.nextBigDecimal();
			k = in.nextInt();
			
			digs = k + 10;
			eps = BigDecimal.valueOf(1, digs - 5);
			
			BigDecimal ans = BigDecimal.ZERO;
			if(x.compareTo(BigDecimal.ONE) <= 0) ans = x;
			else ans = Newton();
			System.out.println(ans.setScale(k, RoundingMode.FLOOR)); // Set precision(set decimal digits).
		}
	}
	
	public static BigDecimal Newton(){
		BigDecimal X = x, pre;
		
		/* Newton's method */
		for(int i = 1; i <= 10000; i++){
			pre = X.subtract(f(X).divide(df(X), digs, RoundingMode.HALF_UP));
			if(X.subtract(pre).compareTo(eps) < 0) break; // Important!!!
			X = pre;
		}
		return X;
	}
	
	public static BigDecimal f(BigDecimal n){
		return n.multiply(n).subtract(x);
	}
	
	public static BigDecimal df(BigDecimal n){
		return n.add(n);
	}
	
}

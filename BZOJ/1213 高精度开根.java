import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {

	static int m;
	static int digs = 10;
	static BigDecimal x;
	static BigDecimal eps = BigDecimal.valueOf(1e-10);

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			m = in.nextInt();
			x = in.nextBigDecimal();
			BigDecimal ans = BigDecimal.ZERO;
			if(m == 1 || x.compareTo(BigDecimal.ONE) <= 0) ans = x;
			else ans = Newton();
//			System.out.println(ans.setScale(10, RoundingMode.HALF_UP)); // Set precision(set decimal digits).
			System.out.println(ans.toBigInteger());
		}
	}
	
	public static BigDecimal Newton(){
		BigDecimal X, pre;
		
		/* Initial value is very important !!! */
		int len = x.toBigInteger().toString().length() / m;
		len ++;
		X = BigDecimal.valueOf(10, -len);
		
		/* Newton's method */
		for(int i = 1; i <= 10000; i++){
			pre = X.subtract(f(X).divide(df(X), digs, RoundingMode.HALF_UP));
			if(X.subtract(pre).compareTo(eps) < 0) break;
			X = pre;
		}
		return X;
	}
	
	public static BigDecimal f(BigDecimal n){
		return n.pow(m).subtract(x);
	}
	
	public static BigDecimal df(BigDecimal n){
		return n.pow(m - 1).multiply(BigDecimal.valueOf(m));
	}
	
	/*   3 1000000000    */
	
}

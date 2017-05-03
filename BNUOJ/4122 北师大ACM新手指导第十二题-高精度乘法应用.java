import java.math.BigDecimal;
import java.util.Scanner;

public class Main {


	public static void main(String[] args) {

		int n;
		BigDecimal x, ans;
		
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			x = in.nextBigDecimal();
			n = in.nextInt();
			
			ans = BigDecimal.ONE;
			while(n != 0){
				if(n % 2 == 1) ans = ans.multiply(x);
				x = x.multiply(x);
				n /= 2;
			}
			String s = ans.stripTrailingZeros().toPlainString(); // !
			if(s.charAt(0) == '0') s = s.substring(1); // !
			System.out.println(s);
		}
	}
	
}

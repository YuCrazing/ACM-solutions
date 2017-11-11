import java.math.BigInteger;
import java.util.Scanner;

public class Main{

	static final int D = 1666;
	static final int mod = 998244353;

	static long[] f = new long[D];
	static long[] cnt = new long[D];
	static long[] sum = new long[D];
	static int[] dig = new int[D];
	static int[] factor = new int[D];
	static int[] perm = new int[D];
	static boolean[] vis = new boolean[D];

	static void init(){
		f[0]=1;
		for(int i = 1; i < D; i++) {
			f[i]=(f[i-1]*i)%mod;
			//System.out.println("f"+i+" "+f[i]);
		}
		sum[0]=sum[1]=0;
		for(int i = 2; i < D; i++) {
			cnt[i]=(f[i]-f[i-1])%mod;
			if(cnt[i]<0) cnt[i] += mod;
			sum[i]=sum[i-1]+cnt[i];
			if(sum[i]>=mod) sum[i]-=mod;
		}
	}

	static int cantor(int len){

		for(int i = 0; i < len; i++) vis[i] = false;

		int ans = 0;
		for(int i = 0; i < len; i++){
			int ct = 0;
			for(int j = perm[i]-1; j >= 0; j--){
				if(vis[j]==false) ct++;
			}
			ans += (f[len-i-1]*ct)%mod;
			if(ans >= mod) ans -= mod;
			vis[perm[i]] = true;
		}
		ans -= f[len-1];
		if(ans < 0) ans += mod;
		return ans+1;
	}

	static int proc(BigInteger x, int d){
		if(d<2) return 0;
		BigInteger dd = BigInteger.valueOf(d);
		BigInteger t = x;
		int len = 0;
		if(x.compareTo(BigInteger.ZERO)==0){
			return 0;
		}else{
			while(t.compareTo(BigInteger.ZERO)!=0){
				dig[len++] = t.mod(dd).intValue();
				t = t.divide(dd);
			}
		}

		if(len<d) return 0; // too small
		if(len>d) return (int)(cnt[d]); // too large

		for(int i = 0; 2*i < len; i++) {
			int tmp = dig[i];
			dig[i] = dig[len-i-1];
			dig[len-i-1]=tmp;
		}

		perm[0] = 1;
		perm[1] = 0;
		for(int i = 2; i < len; i++){
			perm[i] = i;
		}

		for(int i = 0; i < len; i++){
			if(dig[i] > perm[i]) break;
			else if(dig[i] < perm[i]) return 0; // too small
		}

		for(int i = 0; i < len; i++){
			perm[i] = len-i-1;
		}

		for(int i = 0; i < len; i++){
			if(dig[i] > perm[i]) return (int) cnt[d]; // too large
			else if(dig[i] < perm[i]) break;
		}

		for(int i = 0; i < len; i++) {
			vis[i] = false;
			perm[i] = -1;
		}

		for(int i = 0; i < len; i++){
			boolean ok = false;
			boolean free = false;
			for(int j = dig[i]; j >= 0; j--){
				if(vis[j]==false){
					perm[i] = j;
					vis[j]=true;
					ok = true;
					if(j<dig[i]) free=true;
					break;
				}
			}
			if(ok == true && free == true){
				for(int j = i+1; j < len; j++) {
					for(int k = len-1; k >= 0; k--){
						if(vis[k]==false){
							perm[j]=k;
							vis[k]=true;
							break;
						}
					}
				}
				break;
			}
			else if(ok == false){
				int pos = 0;
				for(int j = i-1; j >= 0; j--){
					boolean sec = false;
					vis[perm[j]] = false;
					for(int num = perm[j]-1; num >= 0; num--){
						if(vis[num]==false){
							perm[j] = num;
							vis[num] = true;
							sec = true;
							break;
						}
					}
					if(sec==true){
						pos = j;
						break;
					}
				}

				for(int j = pos+1; j < len; j++){
					for(int k = len-1; k>=0; k--){
						if(vis[k]==false){
							perm[j] =k;
							vis[k] = true;
							break;
						}
					}
				}
				break;
			}

		}

//		for(int i = 0; i < len; i++){
//			System.out.print(dig[i]);
//		}
//		System.out.println();
//		for(int i = 0; i < len; i++){
//			System.out.print(perm[i]);
//		}
//		System.out.println();

		return cantor(len);
	}

	static int calc(BigInteger x, int len){
		int d=-1;
		for(int i = 2; i < D; i++){
			if((i*Math.log10(i)+1) >= len){
				d = i;
				break;
			}
		}
		int ans = 0;
		int a = proc(x, d);
		int b = proc(x, d-1);
		ans += a;
		if(ans >= mod) ans -= mod;
		ans += b;
		if(ans >= mod) ans -= mod;
		ans += sum[d-2];
		if(ans >= mod) ans -= mod;
		return ans;
	}

	static public void main(String arg[]){
		int T;
		Scanner in = new Scanner(System.in);
		BigInteger a, b;
		String sa, sb;

		init();

		T = in.nextInt();
		while(T-->0){
			a = in.nextBigInteger();
			b = in.nextBigInteger();
			a = a.subtract(BigInteger.ONE);
			sa = a.toString();
			sb = b.toString();

			int ans = (calc(b, sb.length())-calc(a, sa.length()))%mod;
			if(ans < 0) ans += mod;
			System.out.println(ans);
		}
	}
}

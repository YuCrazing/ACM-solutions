import java.math.*;
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String [] args)
	{
		int i,j,n;
		n=10;
		int[] a=new int[110];
		int[] b=new int[110];
		//read


//		FileInputStream fis = null;
//		try {
//			fis = new FileInputStream("permutations.in");
//		} catch (FileNotFoundException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//		System.setIn(fis);

		//Scanner cin=new Scanner(System.in);
		Scanner cin=null;
		try{cin=new Scanner(new FileInputStream("permutations.in"));}catch(Exception e){}
		//Scanner cin=new Scanner(System.in);
		n=cin.nextInt();
		for(i=1;i<=n;i++)a[i]=cin.nextInt();
		for(i=1;i<=n;i++)b[i]=cin.nextInt();

		BigInteger sa,sb;
		sa=BigInteger.ZERO;
		sb=BigInteger.ZERO;
		BigInteger[] fac=new BigInteger[110];
		fac[0]=BigInteger.ONE;
		for(i=1;i<=100;i++)
		{
			fac[i]=fac[i-1].multiply(BigInteger.valueOf(i));
		}
		for(i=1;i<=n;i++)
		{
			sa=sa.multiply(BigInteger.valueOf(101));
			sa=sa.add(BigInteger.valueOf(a[i]));
		}
		sa=sa.subtract(BigInteger.ONE);
		for(i=n;i>0;i--)
		{
			a[i]=sa.mod(BigInteger.valueOf(101)).intValue();
			sa=sa.divide(BigInteger.valueOf(101));
		}
		sa=BigInteger.ZERO;
		sb=BigInteger.ZERO;
		//for(i=1;i<=n;i++)System.out.println(a[i]);
		boolean[] vis=new boolean[110];
		for(i=1;i<=n;i++)vis[i]=false;
		for(i=1;i<=n;i++)
		{
			int cnt=-1,mx=0;
			for(j=1;j<=n;j++)
			{
				if(!vis[j]&&j<=a[i])
				{
					cnt++;
					mx=j;
				}
			}
			if(mx==0)break;
			if(mx<a[i]||(i==n&&mx==a[i]))
			{
				sa=sa.add(fac[n-i].multiply(BigInteger.valueOf(cnt+1)));
				break;
			}
			sa=sa.add(fac[n-i].multiply(BigInteger.valueOf(cnt)));
			//System.out.println(sa);
			vis[mx]=true;
		}
		//System.out.println("QAQ");
		for(i=1;i<=n;i++)vis[i]=false;
		for(i=1;i<=n;i++)
		{
			int cnt=-1,mx=0;
			for(j=1;j<=n;j++)
			{
				if(!vis[j]&&j<=b[i])
				{
					cnt++;
					mx=j;
				}
			}
			if(mx==0)break;
			if(mx<b[i]||(i==n&&mx==b[i]))
			{
				sb=sb.add(fac[n-i].multiply(BigInteger.valueOf(cnt+1)));
				break;
			}
			sb=sb.add(fac[n-i].multiply(BigInteger.valueOf(cnt)));
			//System.out.println(sb);
			vis[mx]=true;
		}

//		PrintStream ps = null;
//		try {
//			ps = new PrintStream(new FileOutputStream("permutations.out"));
//			System.setOut(ps);
//			System.out.println(sb.subtract(sa));
//			ps.close();
//		} catch (FileNotFoundException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
		//System.out.println("df");
		 try {
			PrintWriter out = new PrintWriter("permutations.out");
			String s=(sb.subtract(sa)).toString();
			//out.write(s);
			out.println(sb.subtract(sa));
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}


	}
}

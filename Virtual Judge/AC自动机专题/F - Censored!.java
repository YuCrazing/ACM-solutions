/*
  这道题目的数据中含有assic码值大于128的字符，使用ISO-8859-1编码可以正确处理这些字符
 */


import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static final int C = 55;
	static final int N = 105;

	static class Node {
		int[] son = new int[C];
		int next;
		boolean bad;
	}

	static class AC {

		Node[] no = new Node[N];
		int tol;

		// 只有 Node[] no = new Node[N] 是不够的。int[] son = new int[C] 是足够的，因为 int
		// 是基本类型
		void newNodes() {
			for (int i = 0; i < N; i++)
				no[i] = new Node();
		}

		int newNode() {
			for (int i = 0; i < C; i++)
				no[tol].son[i] = 0;
			no[tol].next = 0;
			no[tol].bad = false;
			return tol++;
		}

		void init() {
			tol = 0;
			newNode();
		}

		void insert(String s) {
			int cur = 0;
			for (int i = 0; i < s.length(); i++) {
				int ch = (int) s.charAt(i);
				if (no[cur].son[id[ch]] == 0)
					no[cur].son[id[ch]] = newNode();
				cur = no[cur].son[id[ch]];
			}
			no[cur].bad = true;
		}

		void bfs(int k) {
			Queue<Integer> q = new LinkedList<Integer>();

			for (int i = 0; i < k; i++)
				if (no[0].son[i] != 0)
					q.add(no[0].son[i]);
			
//			while (q.peek()!=null) { 
//				int fa = q.peek();
//				q.remove();
			while (!q.isEmpty()) { 
				int fa = q.remove(); // int 与  Integer 可以相互自动转化？
				
				int nex = no[fa].next;
				if (no[nex].bad)
					no[fa].bad = true;
				
				for (int i = 0; i < k; i++) {
					int son = no[fa].son[i];
					if (son == 0) {
						no[fa].son[i] = no[nex].son[i];
						continue;
					}
					no[no[fa].son[i]].next = no[nex].son[i];
					if (no[fa].bad)
						no[son].bad = true;
					q.add(son);
				}
			}
		}

		void debug(int k) {
			for (int i = 0; i < tol; i++) {
				System.out.println("--------");
				System.out.println("node[" + i + "].next=" + no[i].next);
				System.out.println("node[" + i + "].bad=" + no[i].bad);
				for (int j = 0; j < k; j++) {
					System.out.println("son" + i + ": " + no[i].son[j]);
				}
			}
		}

	}

	static int n, m, p;
	static int[] id = new int[256]; // 128 is not enough
	static String s;
	static AC ac = new AC();
	static BigInteger[][] dp = new BigInteger[55][N];

	static void init() {
		ac.init();
		for(int i = 0; i < 256; i++) id[i] = -1;
	}

	public static void main(String[] args) {
		ac.newNodes();
        Scanner in = new Scanner(new BufferedInputStream(System.in), "ISO-8859-1");
		//Scanner in = new Scanner(System.in);

		init();

		n = in.nextInt();
		m = in.nextInt();
		p = in.nextInt();

		s = in.nextLine(); // 接收'\n'
		s = in.nextLine();
		
		for (int i = 0; i < n; i++) {
			id[(int)s.charAt(i)] = i;
		}

		for (int i = 0; i < p; i++) {
			s = in.nextLine();
			ac.insert(s);
		}

		ac.bfs(n);

		// ac.debug(n);

		for (int i = 0; i <= m; i++) {
			for (int j = 0; j < ac.tol; j++) {
				dp[i][j] = BigInteger.ZERO;
			}
		}

		dp[0][0] = BigInteger.ONE;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < ac.tol; j++) {
				if (ac.no[j].bad)
					continue;
				if (dp[i][j].compareTo(BigInteger.ZERO) == 0)
					continue;
				for (int k = 0; k < n; k++) {
					int nex = ac.no[j].son[k];
					if (ac.no[nex].bad == false) {
						dp[i + 1][nex] = dp[i + 1][nex].add(dp[i][j]);
					}
				}
			}

		}

		BigInteger ans = BigInteger.ZERO;
		for (int j = 0; j < ac.tol; j++) {
			ans = ans.add(dp[m][j]);
		}

		System.out.println(ans);

	}

}
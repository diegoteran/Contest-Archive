import java.util.*;
import java.math.*;

class Main{
	static BigInteger [][] choose = new BigInteger[210][210];
	
	public static void main(String[] args){
		int i, j, T, N, K, n;
		
		for (i = 0; i < 210; i++){
			choose[i][0] = BigInteger.ONE;
			choose[i][i] = BigInteger.ONE;
			for (j = 1; j < i; j++){
				choose[i][j] = choose[i-1][j].add(choose[i-1][j-1]);
			}
		}
		
		Scanner sc = new Scanner(System.in);
		
		for (T = sc.nextInt(); T > 0; T--){
			
			N = sc.nextInt();
			K = sc.nextInt();
			n = 0;
			for (i = 0; i < K; i++){
				n += sc.nextInt();
			}
			if (N - n >= K - 1)
				System.out.println(choose[N - n + 1][K].toString());
			else 
				System.out.println(0);
			
		}
		
		
	}
}
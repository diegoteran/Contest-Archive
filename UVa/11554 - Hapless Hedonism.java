import java.util.*;
import java.math.*;

class Main
{
	public static void main (String[] args) 
	{
		int N, T;
		BigInteger temp;
		Scanner sc = new Scanner(System.in);
		BigInteger tr[] = new BigInteger[1000001];
		tr[0] = BigInteger.ZERO; 
		tr[1] = BigInteger.ZERO; 
		tr[2] = BigInteger.ZERO; 
		tr[3] = BigInteger.ZERO; 
		tr[4] = BigInteger.ONE;
		for (int i = 5; i < 1000001; i++){
			if(i%2 == 0){
				temp = BigInteger.valueOf((i-2)/2);
				temp = temp.multiply(BigInteger.valueOf((i-2)/2));
				tr[i] = tr[i-1].add(temp);
			}
			else{
				temp = BigInteger.valueOf((i-3)/2);
				temp = temp.multiply(BigInteger.valueOf((i-1)/2));
				tr[i] = tr[i-1].add(temp);
			}
		}
		
		T = sc.nextInt();
		for (int i = 0; i < T; i++){
			N = sc.nextInt();
			System.out.println(tr[N]);
		}
		
		
		
	}
}
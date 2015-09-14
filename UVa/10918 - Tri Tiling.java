import java.util.*;
import java.math.*;

/*DP boba */

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int i, j, N;
		BigInteger a[] = new BigInteger [31];
		a[0] = BigInteger.ONE;
		a[1] = BigInteger.ZERO;
		a[2] = BigInteger.valueOf(3);
		for(i = 2; i < 31; i++){
			a[i] = a[i-2].multiply(BigInteger.valueOf(3));
			for(j = 4; i-j >= 0; j+=2)
				a[i] = a[i].add(a[i-j].multiply(BigInteger.valueOf(2)));
		}	
		Scanner sc = new Scanner(System.in);
		j = sc.nextInt();
		while(j >= 0){
			System.out.println(a[j]);
			j = sc.nextInt();
		}
		
	}
}
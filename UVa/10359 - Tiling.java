import java.util.*;
import java.math.*;

/*DP Boba */

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int i, j, N;
		BigInteger a[] = new BigInteger [251];
		a[0] = a[1] = BigInteger.ONE;
		for(i = 2; i < 251; i++)
			a[i] = a[i-1].add(a[i-2].add(a[i-2]));
			
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextInt())
			System.out.println(a[sc.nextInt()]);
		
	}
}
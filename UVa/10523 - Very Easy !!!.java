/* package whatever; // don't place package name! */


import java.lang.*;
import java.io.*;
import java.util.*;
import java.math.*;
 
 
public class Main
{
	public static void main (String[] args)
	{	
		BigInteger A,sum;
		int N, a, i;
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextInt()){
			
			sum = BigInteger.valueOf(0);
			N = sc.nextInt();
			a = sc.nextInt();
			A = BigInteger.valueOf(a);
			
			for(i=1; i<=N; i++)
					sum = sum.add(A.pow(i).multiply(BigInteger.valueOf(i)));
			
			System.out.println(sum);
			
				
		}
	}
} 
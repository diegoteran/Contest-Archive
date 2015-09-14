/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner lec = new Scanner(System.in);
		int N = lec.nextInt();	
		int D = lec.nextInt();
		BigInteger a, res; 
		while(N>0){
			for(a=BigInteger.valueOf(N), res=BigInteger.valueOf(1); D>0; a=a.multiply(new BigInteger(a.toString())), D/=2)
				if(D%2==1)
					res=res.multiply(new BigInteger(a.toString()));
			System.out.println(res.toString());
			N = lec.nextInt();	
			D= lec.nextInt();
		}
	}
}
import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args){
		int i, j;
		BigInteger [][] choose = new BigInteger[205][205];
		
		for (i = 0; i < 205; i++){
			choose[i][0] = choose[i][i] = BigInteger.ONE;
			for (j = 1; j < i; j++)
				choose[i][j] = choose[i-1][j].add(choose[i-1][j-1]);
		}
		
		
		for (i = 0; i < 205 ; i++){
			for (j = 0; j <= i; j++){
					if (j > 0)
						System.out.print(" ");
					System.out.print(choose[i][j]);
			}	
			System.out.println();
		}
		
	}
}
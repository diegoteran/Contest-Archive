import java.util.*;
import java.math.*;


class Main
{
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger p, q, g;
		for(int n = sc.nextInt(); n > 0; n--){
			p = sc.nextBigInteger();
			sc.next();
			q = sc.nextBigInteger();
			g = p.gcd(q);
			p = p.divide(g);
			q = q.divide(g);
			System.out.println(p.toString() +" / " +q.toString());
		}
		
	}
}
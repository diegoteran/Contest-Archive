#include <cstdio>
using namespace std;

int fib[2][2], cop[2][2], cop2[2][2], s1,s2,s3,s4;

void copy(){
	cop2[0][0] = cop[0][0];
	cop2[0][1] = cop[0][1];
	cop2[1][0] = cop[1][0];
	cop2[1][1] = cop[1][1];
}


void mult(int n, int m){
	fib[0][0] = 1;
	fib[0][1] = 0;
	fib[1][0] = 0;
	fib[1][1] = 1;
	
	cop[0][0] = 1;
	cop[0][1] = 1;
	cop[1][0] = 1;
	cop[1][1] = 0;
	
	for( ; n; n /= 2){
		if(n%2){
			s1 = (fib[0][0]*cop[0][0] + fib[0][1]*cop[1][0])%m;
			s2 = (fib[0][0]*cop[0][1] + fib[0][1]*cop[1][1])%m;
			s3 = (fib[1][0]*cop[0][0] + fib[1][1]*cop[1][0])%m;
			s4 = (fib[1][0]*cop[0][1] + fib[1][1]*cop[1][1])%m;
			fib[0][0] = s1;
			fib[0][1] = s2;
			fib[1][0] = s3;
			fib[1][1] = s4;
		}
		copy();
		cop[0][0] = (cop2[0][0]*cop2[0][0] + cop2[0][1]*cop2[1][0])%m;
		cop[0][1] = (cop2[0][0]*cop2[0][1] + cop2[0][1]*cop2[1][1])%m;
		cop[1][0] = (cop2[1][0]*cop2[0][0] + cop2[1][1]*cop2[1][0])%m;
		cop[1][1] = (cop2[1][0]*cop2[0][1] + cop2[1][1]*cop2[1][1])%m;
	}		
	
}

int T, a, b, n, m;

int main() {
	int i, mod;
	scanf("%d", &T);
	while(T--){
		
		scanf("%d %d %d %d", &a, &b, &n, &m);
		mod = 1;
		for (i = 0; i < m; i++)
			mod *= 10;
			
		mult( n, mod);
		if(n)
			printf("%d\n", (a*fib[1][1] + b*fib[1][0])%mod); 
		else
			printf("%d\n", a);
	}
	
}
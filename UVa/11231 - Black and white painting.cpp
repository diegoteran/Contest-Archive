#include <iostream>
#include <cstdio>
using namespace std;

long long N,M,C,res;

int main() {
	
	while(scanf("%lld %lld %lld", &N, &M, &C), N){
		
		N-=7;
		M-=7;
		res = N*M/2;
		if(N%2!=0 && M%2!=0 && C==1)
			res++;
		
		printf("%lld\n", res);
	}
	
}
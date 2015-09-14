#include <iostream>
#include <cstdio>
using namespace std;
long long N;
long long count,i;

void print(long long n){
	if(n>0){
	print(n/2);
	printf("%lld", n%2);
	}
}


int main() {
	
	while(scanf("%lld", &N), N){
		count=0;
		for(i=N; i; i/=2 )
			if(i%2!=0) 
				count++;
		
		if(!i) {
			printf("The parity of ");
			print(N);
			printf(" is %lld (mod 2).\n", count);
		}
	}
	
}
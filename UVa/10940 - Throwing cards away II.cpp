#include <iostream>
#include <cstdio>
using namespace std;

long long N;

long long rec(long long a){
	if(a==1)
		return 1;
	if(a%2==0)
		return 2*rec(a/2);
	return 2 + 2*(rec(a/2)%(a/2));
}

int main() {
	int sum;
	while( scanf("%lld", &N) , N){
		
		printf("%lld\n", rec(N));
		
	}
}
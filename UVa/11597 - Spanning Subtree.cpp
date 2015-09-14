#include <iostream>
#include <cstdio>
using namespace std;

long long N;

int main() {
	int caso = 1;
	while(scanf("%lld", &N), N){
		printf("Case %d: %lld\n",caso++, N/2);
	}
}
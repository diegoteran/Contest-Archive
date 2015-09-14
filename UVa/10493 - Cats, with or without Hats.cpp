#include <cstdio>
#include <algorithm>
using namespace std;

/*Despejar sistema de ecuaciones,  ver cuando no se cumple lo pedido. Gatos deben ser enteros */

long long N,M;

int main() {
	while(scanf("%lld %lld", &N, &M), N){
		if(N == 1){
			if(M == 1)
				printf("%lld %lld Multiple\n", N, M);
			else
				printf("%lld %lld Impossible\n", N, M);
		} else{
			if(__gcd( M*N - 1, N-1) == N-1)
				printf("%lld %lld %lld\n", N, M, (M*N-1)/(N-1));
			else
				printf("%lld %lld Impossible\n", N, M);
		}
		
	}
}
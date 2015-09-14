#include <cstdio>
using namespace std;

/*Inclusión - exclusión */

int T, N, K;
long long sum, k;

int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &K);
		sum = 0;
		for(k = 1; k <= N; k *= K*K)
			sum += N/k - N/k/K;
		
		printf("%lld\n", sum);
	}
}
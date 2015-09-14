#include <cstdio>
using namespace std;

/*La solución es N*2^(N-1) */
#define MOD 1000000007

long long N, T, r, n, m;

int main() {
	int i;
	scanf("%lld", &T);
	for (i = 1; i <= T; i++){
		scanf("%lld", &N);
		r = 1;
		m = 2;
		for (n = N-1; n > 0; n/=2){
			if( n%2)
				r = (r*m)%MOD;
			m = (m*m)%MOD;
		}
		r = (r*N)%MOD;
		printf("Case #%d: %lld\n", i, r);
	}
	
}
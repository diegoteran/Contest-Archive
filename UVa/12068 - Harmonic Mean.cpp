#include <cstdio>
#include <algorithm>
using namespace std;

int T, N, ar[10];
long long n, m, g;

int main() {
	
	int t, i;
	scanf("%d", &T);
	
	for (t = 1; t <= T; t++){
		
		fill ( ar, ar + 10, 0);
		m = 0;
		n = 1;
		scanf("%d", &N);
		for (i = 0; i < N; i++){
			scanf("%d", &ar[i]);
			n *= ar[i];
		}
		for (i = 0; i < N; i++)
			m += n / ar[i];
		
		g = __gcd( n, m);
		n /= g;
		m /= g;
		n *= N;
		g = __gcd( n, m);
		
		
		printf("Case %d: %lld/%lld\n", t, n/g, m/g);
		
	}
}
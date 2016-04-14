#include <cstdio>
#include <algorithm>

using namespace std;

long long t, T, K, C, S;

int main(){

	scanf("%lld", &T);
	while (t++, T--){
		scanf("%lld %lld %lld", &K, &C, &S);
		long long ans = 1;
		for (long long i = 1; i < C; i++)
			ans *= K;
		
		printf("Case #%lld: ", t);
		if (K == 1){ printf("1\n"); continue;}
		
		for (long long i = ans; i < ans*K; i += ans){
			printf("%lld ", i);
		}
		printf("%lld\n", ans*K);

	}

}

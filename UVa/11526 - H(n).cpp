#include <cstdio>
#include <algorithm>
using namespace std;

/* Se resuelve o(sqrt(N)) viendo cómo se comportan los residuos */

int T, N;

int main() {
	int prev, next, i;
	long long ans;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		if(N > 0){
			ans = prev = N;
			for(i = 2; i <= sqrt(N); i++){
				next = N/i;
				ans += next + (prev - next)*(i - 1);
				prev = next;
			}
			if(sqrt(N) < prev)
				ans += sqrt(N);
				
			printf("%lld\n", ans);
		} else
			printf("0\n");
	}
}
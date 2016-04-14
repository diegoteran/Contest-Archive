#include <cstdio>
#include <algorithm>

using namespace std;

long long N, t, T;
bool d[10];

bool check(long long n){
	for (; n; n /= 10)
		d[n%10] = true;

	for (int i = 0; i < 10; i++)
		if(!d[i])
			return false;

	return true;
}

int main(){

	scanf("%lld", &T);
	while (t++, T--){
		fill(d, d+10, false);
		scanf("%lld", &N);
		if(N){
			long long M;
			for (M = N; !check(M); M += N);
			printf("Case #%lld: %lld\n", t, M);
		}else
			printf("Case #%lld: INSOMNIA\n", t);
			

	}

}

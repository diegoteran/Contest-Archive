#include <cstdio>
using namespace std;

unsigned long long N, K;
int a, b;

int main() {
	int t = 0;
	while(scanf("%d %d", &a, &b), t++,  a + b){
		K = b*(b-1)/2;
		N = a*(a-1)/2;
		N *= K;
		printf("Case %d: %lld\n", t, N);
	}
}
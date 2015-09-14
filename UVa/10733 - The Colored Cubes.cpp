#include <cstdio>
using namespace std;

/* Combinatoria, sacar la función */

long long n, r;

int main() {
	while(scanf("%lld", &n), n){
		r = n*n*n*n*n*n;
		r += 3*n*n*n*n;
		r += 12*n*n*n;
		r += 8*n*n;
		printf("%lld\n", r/24);
	}
}
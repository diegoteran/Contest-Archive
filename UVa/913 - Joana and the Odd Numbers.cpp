#include <cstdio>
using namespace std;

long long N, res, cant;

/* cant^4 - (cant^2 - 3)^2 */

int main() {
	
	while (scanf("%lld", &N) != EOF){
		
		cant = (N+1)/2;
		res = 6*cant*cant - 9;
		printf("%lld\n", res);
		
	}
	
}
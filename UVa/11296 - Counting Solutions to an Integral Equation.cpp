#include <cstdio>
using namespace std;

long long N;

int main() {
	while(scanf("%lld", &N)  != EOF)
		printf("%lld\n", (N/2 + 1)*(N/2 + 2)/2);
}
#include <cstdio>
#include <set>
using namespace std;

/* DP lineal no da, checar patrón y condición con teoría de juegos*/

set<long long> s;
long long x, n;

int main() {
	for (x = 1; x <= 1e9; x = 2*x +1)
		s.insert(x);
	
	while(scanf("%lld", &n), n)
		printf(s.find(n) == s.end() ? "Alice\n" : "Bob\n");
}
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

/*Fijarte que sólo te importan los cuadrados */

long long T, N;
stack<long long> s;

int main() {
	long long t, i;
	scanf("%lld", &T);
	for (t = 1; t <= T; t++){
		
		printf("Case %lld:", t);
		
		scanf("%lld", &N);
		for (i = 1; i < 1e5; i++){
			if (N - i*i > 0 &&  __gcd(N- i*i, i) == i )
				s.push(N - i*i);
		}
		
		for (; s.size();  s.pop())
			printf(" %lld", s.top());
		printf("\n");
	}
}
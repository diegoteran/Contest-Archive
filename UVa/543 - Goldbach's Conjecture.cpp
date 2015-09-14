#include <cstdio>
using namespace std;

#define MAXN 1000010

bool isNotPrime[MAXN];
int n, a, b;

int main() {
	int i, j;
	/*Sieve*/
	for (i = 4; i < MAXN; i += 2)
		isNotPrime[i] = true;
		
	for (i = 3; i*i < MAXN; i += 2)
		if(!isNotPrime[i])
			for(j = 2*i; j < MAXN; j += i)
				isNotPrime[j] = true;
	
	while(scanf("%d", &n), n){
		
		for (i = 3; i < n; i+=2){
			if(!isNotPrime[i] && !isNotPrime[n-i]){
				a = i; 
				b = n - i;
				break;
			}
		}
		
		printf("%d = %d + %d\n", n, a, b);
		
	}
}
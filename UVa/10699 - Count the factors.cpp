#include <cstdio>
using namespace std;

#define MAXN 1000010

int n, isNotPrime[MAXN];
/*Count different prime factors*/

int main() {
	int i, j, ans, last;
	/*Modified Sieve*/
	
	for (i = 4; i < MAXN; i += 2)
		isNotPrime[i] = 2;
		
	for (i = 3; i*i < MAXN; i += 2)
		if(!isNotPrime[i])
			for(j = 2*i; j < MAXN; j += i)
				isNotPrime[j] = i;
				
	while(scanf("%d", &n), n){
		i = n;
		ans = 0;
		last = -1;
		while(i > 1){
			if(isNotPrime[i]){
				if(last != isNotPrime[i])
					ans++;
				last = isNotPrime[i];
				i /= isNotPrime[i];
			} else{
				if(last != i)
					ans++;
				break;
			}
		}
		printf("%d : %d\n", n, ans);
	}
}


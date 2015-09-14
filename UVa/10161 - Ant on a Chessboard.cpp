#include <cstdio>
#include <algorithm>

using namespace std;
int N;

int main() {
	int i, M, r, c, count;
	while(scanf("%d", &N), N){
		M = sqrt(N-1) + 1;
		r = M;
		c = 1;
		count = (M-1)*(M-1) + 1;
		while(count!=N){
			count++;
			if(c==M)
				r--;
			else	
				c++;
		}
		if(M%2)
			printf("%d %d\n", r, c);
		else
			printf("%d %d\n", c, r);
	}
	
	
}
#include <cstdio>
using namespace std;

long long N, P, left, curr;

int main() {
	int x, y, k;
	while(scanf("%lld %lld", &N, &P), N+P) {
		
		for(k=1; k*k<= P; k+=2);
		k-=2;
		x = (N+1)/2 + k/2;
		y = (N+1)/2 + k/2;
		curr = k*k;
		
		left= P - curr;
		while(left--){
			if(k*k < curr && curr < k*k + k + 1)
				x--;
			else if(k*k + k + 1 <= curr && curr < k*k + 2*k + 2)
				y--;
			else if(k*k + 2*k + 2 <= curr && curr < k*k + 3*k + 3)
				x++;
			else
				y++;
			curr++;
		}
		
		printf("Line = %d, column = %d.\n", y, x);
		
		
	}
	
}
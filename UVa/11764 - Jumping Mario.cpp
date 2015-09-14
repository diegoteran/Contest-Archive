#include <cstdio>
using namespace std;

int T, N;

int main() {
	int i, t = 0, a, b, low, high;
	scanf("%d", &T);
	while(t++, T--){
		low = high = 0;
		scanf("%d", &N);
		scanf("%d", &a);
		for (i = 1; i < N; i++){
			scanf("%d", &b);
			if(b > a)
				high++;
			if(a > b)
				low++;
			a = b;
		}
		printf("Case %d: %d %d\n", t, high, low);
	}
	
}
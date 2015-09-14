#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000005

long long N, i, j, b[MAXN], lastLeft[MAXN], lastRight[MAXN], ans;

int main(){
	scanf("%lld", &N);
	for (i = 1; i <= N; i++)
		scanf("%lld", &b[i]);
	b[0] = -1; b[N+1] = -1;
	
	//All nearest smaller value(both sides)
	fill(lastRight, lastRight+N+2, N+1);
	for (i = 1; i <= N; i++){
		for (j = i-1; b[j] >= b[i]; j = lastLeft[j]);
		lastLeft[i] = j;
		for (j = (N-i+2); b[j] >= b[N-i+1]; j = lastRight[j]);
		lastRight[N-i+1] = j;
	}
	ans = 0;
	for (i = 1; i <= N; i++)
		ans = max(ans, b[i]*(lastRight[i] - lastLeft[i] - 1));
	
	printf("%lld\n", ans);
}

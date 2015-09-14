#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 1000000000000000

int N, M;
long long dp[310][310];

int main() {
	int i, j, k;
	for (i = 1; i < 310; i++)
		dp[i][1] = dp[1][i] = i-1;
	
	for (i = 2; i < 310; i++){
		
		for (j = 2; j < 310; j++){
dp[i][j] = INF;
			for (k = 1; k < i; k++)
				dp[i][j] = min(dp[i][j], dp[i-k][j] +1+ dp[k][j]);
			for (k = 1; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][j-k] +1+ dp[i][k]);
		}
	}
	while(scanf("%d %d", &N, &M) == 2){
		printf("%lld\n", dp[N][M]);
	}
}
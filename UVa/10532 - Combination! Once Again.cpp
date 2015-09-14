#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 60

long long dp[MAXN][MAXN];
int ar[MAXN];
int n, m;

int main() {
	
	int i, j, k, temp, test = 0;
	while (scanf("%d %d", &n, &m), test++, n){
		
		printf("Case %d:\n", test);
		
		for (i = 0; i < MAXN; i++)
			for (j = 0; j < MAXN; j++)
				dp[i][j] = 0;
				
		fill(ar, ar + n + 1, 0);
		
		for (i = 0; i < MAXN; i++)
			dp[i][0] = 1;
			
		for (i = 0; i < n; i++){
			scanf("%d", &temp);
			ar[temp]++;
		}
		
		for (i = n; i > 0; i--)
			for (j = 1; j <= n; j++)
				for (k = 0; j - k >= 0 && k <= ar[i]; k++)
					dp[i][j] += dp[i+1][j-k];
					
		for (i = 0; i < m; i++){
			scanf("%d", &temp);
			printf("%lld\n", dp[1][temp]);	
		}
		
	}
	
	
}
	
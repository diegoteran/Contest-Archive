#include <cstdio>
#include <algorithm>
using namespace std;

int k;
unsigned long long n;
unsigned long long dp[1010][64];

int main() {
	int i, j, mini;
	
	for (i = 1; i < 1010; i++)
		for (j = 1; j < 64; j++)
			dp[i][j] = dp[i][j-1] + dp[i-1][j-1] + 1;
			
	while (scanf("%d %llu", &k, &n), k){
		mini = 64;
		for (j = 63; j > 0; j--){
			if (dp[k][j] >= n)
				mini = j;
		}		
		if(mini == 64)
			printf("More than 63 trials needed.\n");
		else
			printf("%d\n", mini);
	}
	
}
#include <cstdio>
#include <algorithm>

using namespace std;

int numbers[60][60], dp[60][60], i, j, x, L;

int main(){
	scanf("%d", &L);
	for ( i = 0; i < L; i++)
		for (j = 0; j <= i; j++)
			scanf("%d", &numbers[i][j]);
		
	dp[0][0] = numbers[0][0];	
	for ( i = 1; i < L; i++){
		
		for (j = 0; j <= i; j++){
			if(j == 0)
				dp[i][j] = dp[i-1][j] + numbers[i][j];
			else if(j == i)
				dp[i][j] = dp[i-1][j-1] + numbers[i][j];
			else
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + numbers[i][j];
		}
	}

	int ax = 0;
	for(i = 0; i < L; i++)
		ax = max(ax, dp[L-1][i]);

	printf("%d\n", ax);
	

}

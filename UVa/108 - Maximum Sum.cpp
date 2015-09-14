#include <iostream>
using namespace std;

#define MAXN 110

int N, grid[MAXN][MAXN], i, j, k, dp[MAXN][MAXN], temp[MAXN], maxx=-127, dpt[MAXN];

int main() {
	
	cin >> N;
	for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
			cin >> grid[i][j];
			
	for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
			dp[i][j] = dp[i-1][j] + grid[i][j];
			
	for(i=0; i<N; i++)
		for(j=i+1; j<=N; j++)
			for(k=1; k<=N; k++){
				temp[k] = dp[j][k] - dp[i][k];
				dpt[k-1] <= 0 ? dpt[k] = temp[k] : dpt[k] = dpt[k-1] + temp[k];
				if(dpt[k] > maxx) 
					maxx = dpt[k];
			}
		
	cout << maxx << "\n";
}
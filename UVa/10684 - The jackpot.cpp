#include <cstdio>
using namespace std;

int N, nums[10010], i, dp[10010], max;

int main() {
	
	while(scanf("%d", &N), N){
		
		max = -1;
		
		for(i=1; i<=N; i++){
			scanf("%d", &nums[i]);
			dp[i] = nums[i] + (dp[i-1] <= 0 ? 0: dp[i-1]); 
			if(dp[i] > max)
				max = dp[i];
		}
		
		if(max > 0)
			printf("The maximum winning streak is %d.\n", max);
		else
			printf("Losing streak.\n");
	}
	
}
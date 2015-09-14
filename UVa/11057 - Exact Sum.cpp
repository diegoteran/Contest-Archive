#include <cstdio>
#include <algorithm>
using namespace std;

int N, p, nums[10010], i, j, low, high;

int main() {
	
	while(scanf("%d", &N) != EOF){
		
		low=0; high=10000000;
		for(i=0; i<N; i++)
			scanf("%d", &nums[i]);
			
		scanf("%d", &p);
			
		sort(nums, nums+N);
		
		i=0; j=N-1;
		while(i!=j){
			if(nums[i]+nums[j]==p)
				if(nums[j]-nums[i] < high-low){
					high = nums[j];
					low = nums[i];
				}
			
			nums[i]+nums[j] <= p ? i++ : j--;
		}
		
		printf("Peter should buy books whose prices are %d and %d.\n\n", low, high);
		
		
	}
	
}
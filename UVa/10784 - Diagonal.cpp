#include <iostream>
#include <cstdio>
using namespace std;

unsigned long long diags[50000000];
long long N;

int main() {
	unsigned long long i, high, low, mid, k=1;
	diags[3] = 0;
	
	for(i=4; i<50000000; i++)
		diags[i] = diags[i-1] + i - 2;
		
	while(scanf("%lld", &N), N){
		
		high=50000000;
		low=1;
		
		while(high!=low){
			mid = (high + low)/2;
			if(diags[mid]>=N)
				high = mid;
			else
				low = mid + 1;
		}
		
		printf("Case %lld: %lld\n", k, low);
		
		
		k++;
	}
	
	return 0;
}
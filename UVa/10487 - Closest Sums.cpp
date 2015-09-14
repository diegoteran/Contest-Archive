#include <iostream>
#include <cstdio>
using namespace std;

int N,M,num[1000];

int main() {
	int i,j,r,temp,k=1,sum,numMin;
	long long min;
	
	while(scanf("%d", &N), N){
		
		for(i=0; i<N; i++)
			scanf("%d", &num[i]);
			
		printf("Case %d:\n", k++);	
		scanf("%d", &M);
		for(i=0; i<M; i++){
			scanf("%d", &temp);
			min = 1000000000;
			
			for(j=0; j<N; j++)
				for(r=j+1; r<N; r++){
					sum = num[j] + num[r];
					if(sum > temp)
						if(sum - temp < min){
							min = sum-temp;
							numMin = sum;
						}
						else;
					else
						if(temp - sum < min){
							min = temp-sum;
							numMin= sum;
						}
				}
			
			printf("Closest sum to %d is %d.\n", temp, numMin);
		}
		
	}
	
}
#include <iostream>
#include <cstdio>
using namespace std;

long long N, B, H, W, w[13];

int main() {
	
	long long i, j, P, mP;
	
	while( scanf("%lld %lld %lld %lld", &N, &B, &H, &W) > 0 ){
	mP=500001;
		
		for(i=0; i<H; i++){
			
			scanf("%lld", &P);
			
			for(j=0; j<W; j++)
				scanf("%lld", &w[j]);
			
			if(P*N <= B)
				for(j=0; j<W; j++)
					if(w[j] >= N){
						if(P*N < mP)
							mP = P*N;
						continue;
					}
					
		}
		
		if(mP != 500001)
			printf("%lld\n", mP);
		else
			printf("stay home\n");
		
	}
	
}

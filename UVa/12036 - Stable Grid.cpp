#include <iostream>
#include <cstdio>
using namespace std;

int T, N, count[101];

/* Para que se cumpla la condición se debe de checar que ningún número se repita
	más que N veces. La demostración en ITAM. */

int main() {
	
	int k,i,j,p,r;
	scanf("%d", &T);
	for(k=1; k<=T; k++){
		r=0;
		for(i=0; i<102; i++)
			count[i] = 0;
			
		scanf("%d", &N);
		for(i=0; i<N; i++)
			for(j=0; j<N; j++){
				scanf("%d", &p);
				count[p]++;
			}
				
		for(i=0; i<102; i++)
			if(count[i]>N)
				r=1;
				
		if(r==1)
			printf("Case %d: no\n", k);
		else
			printf("Case %d: yes\n", k);
		
	}
	
}
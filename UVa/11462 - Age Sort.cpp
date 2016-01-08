#include <cstdio>
#include <algorithm>

using namespace std;

int cont[105], N, i, temp, c;

int main(){

	while(scanf("%d", &N), N){
		
		c = N;
		fill(cont, cont +101, 0);
		for(i = 0; i < N; i++){		
			scanf("%d", &temp);
			cont[temp]++;		
		}

		for(i = 1; i <= 100; i++)
			while(cont[i]--){
				if(c != 1)	
					printf("%d ", i);
				else
					printf("%d", i);
				c--;
			}		
			printf("\n");
	}
}

#include <cstdio>
using namespace std;

/* todos los pares se pueden y juntarlos en conjuntos de 4 y de 6 */
int N, n;

int main() {
	int i, j, k;
	while (scanf("%d", &N), N){
		n = N;
		if(N % 2 || N == 2)
			printf("Impossible\n");
		else if(!(N % 4)){
			printf("%d\n", N/2*3);
			for (i = 1, j = 4; i <= j && j <= N; i++){
				for(k = i+1; k <= j; k++)
					printf("%d %d\n", i, k);
				
				if (i == j)
					j += 4;
			}
			
		} else {
			printf("%d\n", N/2*3);
			for (i = 1, j = 4; i <= j && j <= N - 6; i++){
				for( k = i+1; k <= j; k++)
					printf("%d %d\n", i, k);
				
				if (i == j)
					j += 4;
			}
			i = N;
			printf("%d %d\n", i-1, i-5);
			printf("%d %d\n", i-5, i-3);
			printf("%d %d\n", i-5, i-2);
			printf("%d %d\n", i-4, i-3);
			printf("%d %d\n", i-4, i-2);
			printf("%d %d\n", i-1, i-4);
			printf("%d %d\n", i, i-2);
			printf("%d %d\n", i, i-3);
			printf("%d %d\n", i, i-1);
			
		}
		
	}
	
}
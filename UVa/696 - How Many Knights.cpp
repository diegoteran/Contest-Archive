#include <cstdio>
using namespace std;

int M,N;

int main() {
	while(scanf("%d%d", &N, &M), N + M){
		if(M>2 && N>2)
			printf("%d knights may be placed on a %d row %d column board.\n", (M*N+1)/2, N, M);
		else{
			if(M==2)
				printf("%d knights may be placed on a %d row %d column board.\n", (N/4)*4 + ((N%4 == 1)? 2 : 4 ) - ((N%4==0)? 4:0) , N, M);
			else
				if(N==2)
					printf("%d knights may be placed on a %d row %d column board.\n", (M/4)*4 + ((M%4 == 1)? 2 : 4 ) - ((M%4==0)? 4:0) , N, M);
				else
					printf("%d knights may be placed on a %d row %d column board.\n", M*N, N, M);
		}
	}
	
}
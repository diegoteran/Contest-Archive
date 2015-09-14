#include <iostream>
#include <cstdio>
using namespace std;

int M,N,R,C,T;

int main() {
	int i,north,south,east,west;
	scanf("%d", &T);
	
	for(i=0; i<T; i++){
		
		scanf("%d %d %d %d", &M, &N, &R, &C); R++; C++;
		north = M-R;
		south = R-1;
		east = C-1;
		west = N-C;
		
		if(north ^ south ^ west ^ east)
			printf("Gretel\n");
		else
			printf("Hansel\n");
		
	}
	
}
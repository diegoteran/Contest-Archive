#include <cstdio>
using namespace std;

int grid[3][3],grid2[3][3], N, i, j, sum;

int suma(){
	sum = 0 ;
	for(i=0; i<3; i++)
			for(j=0; j<3; j++)
				sum += grid[i][j];
	return sum;
}

void copia(){
	for(i=0; i<3; i++)
			for(j=0; j<3; j++)
				grid2[i][j] = grid[i][j];
}

void f(){
	grid[0][0] = (grid2[0][1] + grid2[1][0])%2;
	grid[2][0] = (grid2[1][0] + grid2[2][1])%2;
	grid[0][2] = (grid2[0][1] + grid2[1][2])%2;
	grid[2][2] = (grid2[2][1] + grid2[1][2])%2;
	grid[0][1] = (grid2[0][0] + grid2[0][2] + grid2[1][1])%2;
	grid[1][0] = (grid2[0][0] + grid2[2][0] + grid2[1][1])%2;
	grid[1][2] = (grid2[0][2] + grid2[2][2] + grid2[1][1])%2;
	grid[2][1] = (grid2[2][0] + grid2[2][2] + grid2[1][1])%2;
	grid[1][1] = (grid2[0][1] + grid2[1][0] + grid2[1][2] + grid2[2][1])%2;
}

int main() {
	
	int temp, k;
	scanf("%d", &N);
	while(N--){
		
		for(i=0; i<3; i++){
			scanf("%d", &temp);
			for(j=2; j>=0; j--, temp/=10){
				grid[i][j] = temp%2;
			}
		}		
		
		copia();	
		for( k=-1; suma() > 0; k++){
			f();
			copia();
		}
			
			
		printf("%d\n", k);
		
	}
	
}
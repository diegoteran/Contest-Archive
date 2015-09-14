#include <cstdio>
using namespace std;


#define MAXN 110
 
long long choose[MAXN][MAXN];
int n, k, sum, r;
 
int main() {
	int i, j, temp;
 
	for (i = 0; i < MAXN; i++){
		choose[i][0] = choose[i][i] = 1;
		for (j = 1; j < i; j++)
			choose[i][j] = (choose[i-1][j] + choose[i-1][j-1]);
	}
	
	while(scanf("%d", &n) == 1){
		scanf("%d", &k);
		sum = 0;
		r = 1;
		for (i = 0; i < k; i++){
			scanf("%d", &temp);
			r *= choose[n - sum][temp];
			sum += temp;
		}
		printf("%d\n", sum <= n ? r : 0);
		
	}
	
	
	
}
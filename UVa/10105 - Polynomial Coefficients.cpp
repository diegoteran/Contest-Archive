#include <cstdio>
using namespace std;

long long choose[14][14];
long long ans;
int N, K;

int main() {
	
	int i, j, temp;
	for (i = 0; i < 14; i++){
		choose[i][0] = choose[i][i] = 1;
		for (j = 0; j < i; j++)
			choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
	}
	
	while (scanf("%d %d", &N, &K) == 2){
		ans = 1;
		for (i = 0; i < K; i++){
			scanf("%d", &temp);
			ans *= choose[N][temp];
			N -= temp;
		}
		printf("%lld\n", ans);
	}
	
}
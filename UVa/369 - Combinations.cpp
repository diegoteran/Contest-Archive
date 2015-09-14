#include <cstdio>

using namespace std;

#define MAXN 110

long long choose[MAXN][MAXN];
int n, k;

int main() {
	int i, j;
	
	for (i = 0; i < MAXN; i++){
		choose[i][0] = choose[i][i] = 1;
		for (j = 1; j < i; j++)
			choose[i][j] = (choose[i-1][j] + choose[i-1][j-1]);
	}
	
	while (scanf("%d %d", &n, &k), n + k)
		printf("%d things taken %d at a time is %lld exactly.\n", n, k, choose[n][k]);
}
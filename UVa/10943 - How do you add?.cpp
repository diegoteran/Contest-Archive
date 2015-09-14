#include <cstdio>

using namespace std;

#define MOD 1000000
#define MAXN 210

long long choose[MAXN][MAXN];
int n, k;

int main() {
	int i, j;
	
	for (i = 0; i < MAXN; i++){
		choose[i][0] = choose[i][i] = 1;
		for (j = 1; j < i; j++)
			choose[i][j] = (choose[i-1][j] + choose[i-1][j-1])%MOD;
	}
	
	while (scanf("%d %d", &n, &k), n)
		printf("%lld\n", choose[n + k -1][k - 1]);
}
#include <cstdio>
using namespace std;

int T, N, M;

int main() {
	int i;
	scanf("%d", &T);
	for (i = 0; i < T; i++){
		scanf("%d %d", &N, &M);
		printf("%d\n", N == M ? ((N+1)/2)*((N+1)/2+1)/2 : ((N+1)/2) * ((M+1)/2));
	}
}
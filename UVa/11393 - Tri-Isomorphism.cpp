#include <cstdio>
using namespace std;

/*Churrazo, aristas divisibles entre 3 */

int N;

int main() {
	while(scanf("%d", &N), N)
		printf( N%3 == 2 || N == 1 ? "NO\n" : "YES\n");
}
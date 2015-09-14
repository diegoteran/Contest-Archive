#include <cstdio>
using namespace std;

int N;

int main() {
	while (scanf("%d", &N) != EOF){
		printf( N%3 > 0 || N < 1 ? "0\n" : "1\n" );
	}
}
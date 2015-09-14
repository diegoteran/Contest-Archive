#include <cstdio>
using namespace std;

int f(int a){
	if(a <= 100)
		return f(f(a+11));
	else
		return a-10;
}

int N;
int main() {
	while(scanf("%d", &N), N){
		printf("f91(%d) = %d\n", N, f(N));
	}
}
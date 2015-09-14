#include <cstdio>
using namespace std;

int N, res;

int main() {
	
	while(scanf("%d", &N) != EOF){
		res = 0;
		while(N >= 3){
			res += N - N%3;
			N = N/3 + N%3;
		}
		res += N;
		if(N == 2)
			res++;
			
		printf("%d\n", res);
		
	}
	
}
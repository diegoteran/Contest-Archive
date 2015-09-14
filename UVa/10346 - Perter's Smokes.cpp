#include <iostream>
#include <cstdio>
using namespace std;

int N,K;

int main() {
	
	while(scanf("%d %d", &N, &K) > 0){
		int sum = N;
		
		int aux = N/K;
		sum += aux;
		int res = N%K + aux;
		while(res>=K){
			sum += res/K;
			res = res/K + res%K; 
		}
		
		printf("%d\n", sum);
	}
	
}
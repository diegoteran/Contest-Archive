#include <bits/stdc++.h>

using namespace std;

int N, K, a, b, c, d;

int main(){
	scanf("%d %d", &N, &K);
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if(K <= N || N == 4){
		printf("-1\n");
	} else{
		printf("%d %d ", a, c);
		for (int i = 1; i <= N; i++){
			if(i != a && i!= b && i != c && i != d)
				printf("%d ", i);
		}
		printf("%d %d\n", d, b);
		printf("%d %d ", c, a);
		for (int i = 1; i <= N; i++){
			if(i != a && i!= b && i != c && i != d)
				printf("%d ", i);
		}
		printf("%d %d\n", b, d);
	}
}

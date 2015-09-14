#include <cstdio>
using namespace std;

int N, ans;

int main() {
	while(scanf("%d", &N), N){
		ans = 0;
		while(N >= 3){
			ans += N/3;
			N = N/3 + N%3;
		}
		if(N == 2)
			ans++;
		printf("%d\n", ans);
	}
}
#include <cstdio>
#include <algorithm>

using namespace std;

int T, N, a[200], temp, m;

int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		m = 0;
		for (int i = 0; i < N; i++)
			scanf("%d", a+i);

		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++)
				m = max(m, __builtin_popcount(a[i]^a[j]));		
		
		printf("%d\n", m);
	}
}

#include <cstdio>
#include <algorithm>

using namespace std;

long long ar[100100], p, q, T, t, N, P, i, j, l, ans, sum;

int main(){
	scanf("%lld", &T);
	for(t = 1; t <= T; t++){
	
		scanf("%lld %lld", &N, &P);
		for(i = 1; i <= N; i++)
			scanf("%lld", &ar[i]);

		p  = 1;	ans = 0;
		sum = ar[1];
		if(ar[1] <= P) ans++;
		for(q = 2, l = 2; q <= N; q++, l++){
			sum += ar[q];
			while(sum > P && l){
				sum -= ar[p++];
				l--;
			}

			if(l)
				ans += l;
		
		}
		printf("Case #%lld: %lld\n", t, ans);
	}
}

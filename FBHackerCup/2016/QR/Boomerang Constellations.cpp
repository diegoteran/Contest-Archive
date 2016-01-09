#include <cstdio>
#include <algorithm>

using namespace std;

long long T, t, N, x, y, i, j, ans, last, c;
pair<long long, long long> stars[2010];
long long d[2010];

long long dist2(int a, int b){

	long long n = (stars[a].first - stars[b].first)*(stars[a].first - stars[b].first);
	return n + (stars[a].second - stars[b].second)*(stars[a].second - stars[b].second);

}

int main(){
	scanf("%lld",&T);
	for(t = 1; t <= T; t++){
		ans = 0;
		scanf("%lld", &N);
		for(i = 0; i < N; i++)
			scanf("%lld %lld", &stars[i].first, &stars[i].second);

		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++)
				d[j] = dist2(i, j);
			
			sort(d, d + N);
			c = 0;	
			for(j = 1; j < N; j++){
				if(d[j] != d[j-1]){
					ans += c*(c+1)/2;	
					c = 0;
				}
				else
					c++;				
			}
			ans += c*(c+1)/2;
		}

		printf("Case #%lld: %lld\n", t, ans);
	}
}

#include <cstdio>
#include <algorithm>

using namespace std;

long long L, N, M, D, W[10100], i, j, T, t, high, low, mid, cont, lt[1000010], dt[1000010];

int main(){

	scanf("%lld", &T);
	while(t++, T--){

		scanf("%lld %lld %lld %lld", &L, &N, &M, &D);
		for(i = 0; i < N; i++)
			scanf("%lld", &W[i]);

		high = 1000000000000000010;
		low = 0;

		while(high != low){

			mid = (high+low)/2;
			cont = L;

			for(i = 0; i < N; i++)
				cont -= mid/W[i];

			if(cont > 0)
				low = mid + 1;
			else
				high = mid;		

		}

		cont = L; 
		for(i = 0; i < N; i++){
			low = high/W[i];
			while(cont && low){
				lt[L - cont] = (high/W[i]-low+1)*W[i];
				cont--; low--;
			}
		}

		sort(lt, lt+L);
		fill(dt, dt+M, 0);
		
		for(i = 0; i < L/M + 1; i++)
			for(j = 0; j < M && M*i + j < L; j++)
				dt[j] = max(lt[M*i + j], dt[j]) + D;

		printf("Case #%lld: %lld\n", t, *max_element(dt, dt+M));

	}

}

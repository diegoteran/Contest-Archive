#include <cstdio>
#include <algorithm>

using namespace std;

int num[100100], T, t, N, d[100100], ans, cont, i, j, last;

int main(){

	scanf("%d", &T);
	while(t++, T--){

		scanf("%d", &N);
		for(i = 0; i < N; i++)
			scanf("%d", &num[i]);

		for(i = 0; i < N-1; i++)
			if(num[i+1]-num[i] <= 0 || num[i+1]-num[i] > 30)
				d[i] = 3;
			else
				d[i] = (num[i+1]-num[i]-1)/10;

		ans = 0; 
		cont = 1;
		last = -1;
		d[N-1] = 3;
		for(i = 0; i < N; i++){
			if(d[i] == 3){
				for(j = last + 1; j <= i; j++){
					if(cont == 4){
						cont = 1;
						continue;
					}
					if(j < i && d[j]==0){
						cont++;
						continue;
					}
					if(j < i && d[j] > 0){
						if(cont + d[j] >= 4){
							ans += 4 - cont;
							cont = 1;
							continue;
						} else{
							ans += d[j];
							cont += d[j]+1;
							continue;
						}

					}
					if(j == i)
						ans += 4 - cont;
					

				}
				last = i;
				cont = 1;
			} 
		}

		printf("Case #%d: %d\n", t, ans);

	}

}

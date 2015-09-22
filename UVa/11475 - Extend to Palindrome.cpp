#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define B 1000001857
#define MOD 1000004933

long long S, i, j, x, h[100005], rh[100005];
char s[100005];

long long bin(long long a, long long b){
	long long res = 1;
	while (b){
		if(b%2)
			res = (res*a)%MOD;
		a = (a*a)%MOD;
		b /= 2;
	}
	return res;
}

long long f(int a, int b){
	long long res = h[b] - h[a-1];
	while (res < 0)
		res += MOD;
	res = (res*bin(bin(B, a), MOD-2))%MOD;
	return res;
}

int main(){

	while (scanf("%s", s) != EOF){
		S = strlen(s);
		x = B; h[0] = s[0]; rh[S-1] = s[S-1];
		for (i = 1; i < S; i++){
			h[i] = (h[i-1] + s[i]*x)%MOD;
			rh[S-1-i] = (rh[S-i] + s[S-1-i]*x)%MOD;
			x = (x*B)%MOD;
		}
		
		printf("%s", s);
		if(h[S-1] != rh[0]){
			for (i = 1; i < S; i++){
				if(f(i, S-1) == rh[i])
					break;
//				printf("%d %d\n", f(i, S-1), rh[i]);
			}
			while (i--){
				printf("%c", s[i]);
			}
		}
		printf("\n");
	}
}

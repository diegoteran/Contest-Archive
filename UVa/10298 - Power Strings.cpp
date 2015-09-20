#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define B 499
#define MOD 10069

int S, N, i, j, h[1000005], x;
char c[1000005];

int getPower(int a, int b){
	int ans = 1;
	int pot = a;
	while(b){
		if (b%2==1)
			ans = (ans*pot)%MOD;	
		pot = (pot*pot)%MOD;
		b /= 2;
	}
	return ans;
}

int f(int a, int b){
	int res = h[b] - h[a-1];
	while (res < 0)
		res += MOD;
	res = (getPower(getPower(B, a), MOD-2)*res)%MOD;
	return res;
}

int main(){
		
	while(scanf("%s", c), !(strlen(c) == 1 && c[0] == '.')){
		S = strlen(c);
		x = B;
		h[0] = c[0];
		for(i = 1; i < S; i++){
			h[i] = (h[i-1] + c[i]*x)%MOD;
			x = (x*B)%MOD;
		}
		
		int answer = 1;
		for(i = S-1; i >= 1; i--){
			if(c[i] == c[0] && S%i==0){
	//			printf("Entered: %d\n", i);
				for(j = i; j < S; j += i)
					if(h[i-1] != f(j, j+i-1)){
	//					printf("Muere en %d\n", j);
	//					printf("%d %d\n", h[i-1], f(j, j+i-1));
						break;
					}
	//				else 
	//					printf("Cumple en %d\n", j);
	//			printf("%d %d\n", j, S);
				if (j == S)
					answer = S/i;
			}
		}
		
		printf("%d\n", answer);
		
	}

}

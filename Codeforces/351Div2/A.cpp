#include <bits/stdc++.h>

using namespace std;

bool minutes[100];
int N, aux, c, ans;

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &aux);
		minutes[aux] = true;
	}
	c = ans = 0;
	for (int i = 1; i <= 90; i++){
		c++;
		ans++;
		if(minutes[i] == true)
			c = 0;
		
		if(c == 15)
			break;
	}
	
	printf("%d\n", ans);
}

#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int N, ch[110], i, j , first, cont;

int main(){

	long long ans = 0; cont = 1;
	
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &ch[i]);
		if(!ch[i] && !first)
			continue;

		if(ch[i]){
			if(!first){
				cont = 0; ans = 1;
			}
			first++;			
			ans *= (cont+1);
			cont = 0;
		} else{
			cont++;

		}
	}
	if(N == 1 && ch[0])
		ans = 1;
	if(N == 1 && !ch[0])
		ans = 0;

	cout << ans << endl;

}

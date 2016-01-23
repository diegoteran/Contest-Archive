#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	long long l, r, k, a, b;
	cin >> l >> r >> k;

	for(a = 1, b = 0; a <= r; a *= k){
		if(a >= l){
			if(b == 0)
				printf("%lld", a);
			else
				printf(" %lld", a);

			b++;
		}
	}
	if(b > 0)
		printf("\n");
	else
		printf("-1\n");

}

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

__int128 conv (__int128 n, int k){
	__int128 res = 0, aux = 1;
	while (n){
		if (n%2)
			res += aux;
		n /= 2;
		aux *= k;
	}
	return res;
}

__int128 check (__int128 n){

	for (__int128 i = 2; i*i <= n; i++)
		if(n%i == 0)
			return i;

	return 0;

}

int main(){

	__int128 N = (1<<31) + 1;
	__int128 t = 0;
	printf("Case #1:\n");
	while(t < 500){

		__int128 a = check(conv(N, 2));
		__int128 b = check(conv(N, 3));
		__int128 c = check(conv(N, 4));
		__int128 d = check(conv(N, 5));
		__int128 e = check(conv(N, 6));
		__int128 f = check(conv(N, 7));
		__int128 g = check(conv(N, 8));
		__int128 h = check(conv(N, 9));
		__int128 k = check(conv(N,10));
		if(a && b && c && d && e && f && g && h && k && (N%2)){
			string str = "";
			__int128 R = N;
			while(R){
				if(R%2)
					str = "1" + str;
				else
					str = "0" + str;
				R /= 2;

			}
			cout << str;
			printf(" %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", a, b, c, d, e, f, g, h, k);
			t++;
		}

		N += 2;
	}

}

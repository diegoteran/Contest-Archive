#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

long long N, dt[MAXN];
bool d[MAXN], v[MAXN];
char c[MAXN];

int main(){

	cin >> N;
	scanf("%s", c);
	for (int i = 0; i < N; i++){
		cin >> dt[i];
		d[i] = (c[i] == '>');
	}
	
	bool ans = false;
	long long pos = 0;
	while (true){

		if (pos < 0 || pos >= N){
			ans = true;
			break;
		}
		if (v[pos]) break;
		v[pos] = true;

		if (d[pos])
			pos += dt[pos];
		else
			pos -= dt[pos];
	}
	
	if (ans) 
		cout << "FINITE" << endl;
	else
		cout << "INFINITE" << endl;


}

#include <bits/stdc++.h>

using namespace std;

string str, aux;
int m, l, r, k;

int main(){
	cin >> str >> m;
	while (m--){

		cin >> l >> r >> k;
		l--; r--;
		k = k % (r - l + 1);
		
		aux = str;
		for (int i = 0; i < r - l + 1; i++)
			aux[l + (i+k)%(r - l + 1)] = str[l + i];
		
		for (int i = 0; i < r - l + 1; i++)
			str[l + i] = aux[l + i];
	
	}
	cout << str << endl;
}

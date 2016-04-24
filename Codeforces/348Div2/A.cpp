#include <bits/stdc++.h>

using namespace std;

int main(){
	long long N;
	cin >> N;
	long long ans = (N/3)*2;
	if (N%3)
		ans++;

	cout << ans << endl;
}

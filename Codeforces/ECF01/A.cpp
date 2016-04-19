#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, t, x;

int main(){

	cin >> t;
	while (t--){

		cin >> n;
		long long hi, lo, mid;
		lo = 0; hi = 50;
		while (hi != lo){
			mid = (hi+lo)/2;
			if ((1LL << mid) <= n)
				lo = mid+1;
			else 
				hi = mid;
		}

		cout << n*(n+1)/2 - 2*((1LL << hi)-1) << endl;

	}
}

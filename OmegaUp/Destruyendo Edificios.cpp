#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define MAXN 1000100

long long ar[MAXN], l[MAXN], r[MAXN], N;

int main(){

	cin >> N;
	for (int i = 1; i <= N; i++)
		scanf("%lld", ar + i);
	
	ar[0] = ar[N+1] = -1;
	for (int i = 1; i <= N; i++) {
		int j = i-1;
		while (ar[j] >= ar[i])
			j = l[j];
		l[i] = j;
	}

	for (int i = N; i > 0; i--) {
		int j = i+1;
		while (ar[j] >= ar[i])
			j = r[j];
		r[i] = j;
	}

	long long M = 0;
	for (int i = 1; i <= N; i++)
		M = max(M, (r[i] - l[i] - 1)*ar[i]);

	cout << M << endl;
}

#include <bits/stdc++.h>

#define INF 1000000000

using namespace std;

int t, n, m, k, dp[35][35][60];

int f(int r, int c, int s){

	if (s > r*c) return INF;
	if (dp[r][c][s]) return dp[r][c][s];
	if (r*c == s || !s) return 0;
	int ans = INF;

	for (int i = 1; i < r; i++)
		for (int j = 0; j <= s; j++)
			ans = min(ans, f(i, c, j) + f(r-i, c, s-j) + c*c);
	
	for (int i = 1; i < c; i++)
		for (int j = 0; j <= s; j++)
			ans = min(ans, f(r, i, j) + f(r, c-i, s-j) + r*r);
	
	return dp[r][c][s] = ans;

}

int main(){

	scanf("%d", &t);
	while (t--){

		scanf("%d %d %d", &n, &m, &k);
		printf("%d\n", f(n, m, k));

	}
}

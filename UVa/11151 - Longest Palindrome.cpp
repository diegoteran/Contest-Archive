#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int T, S, dp[1005][1005], i, j;
string s;

int main(){

	scanf("%d", &T);
	getline(cin, s);
	while (T--){
	
		getline(cin, s);
		S = s.size();

		for (i = 0; i < S; i++)
			for (j = 0; j < S; j++){
				dp[i][j] = 0;
				if(i==j)
					dp[i][j]++;
			}

		for (j = 1; j < S; j++)
			for (i = j-1; i >= 0; i--){
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
				if(s[i] == s[j])
					dp[i][j] = max(2+dp[i+1][j-1], dp[i][j]);
			}
		
		printf("%d\n", (S>0 ? dp[0][S-1] : 0));

	}

}

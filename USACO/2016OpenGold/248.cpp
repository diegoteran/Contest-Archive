#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int ar[250], N, dp[250][250], ans;

int main(){

	ifstream in ("248.in");
	ofstream out ("248.out");

	in >> N;
	for (int i = 0; i < N; i++)
		in >> ar[i];

	for (int i = 0; i < N; i++)
		dp[i][i] = ar[i];
	

	ans = *max_element(ar, ar+N);
	for (int k = 1; k < N; k++){
		for (int i = 0; i+k < N; i++){
			for (int j = i; j < i+k; j++){
				if (dp[i][j] == dp[j+1][i+k] && dp[i][j]) 
					dp[i][i+k] = max(dp[i][i+k], dp[i][j]+1);
			}
			ans = max(ans, dp[i][i+k]);
		}
	}

	out << ans << endl;

}

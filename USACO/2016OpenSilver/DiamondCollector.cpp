#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define MAXN 50010

int ar[MAXN], N, K, bl[MAXN], br[MAXN], dpl[MAXN], dpr[MAXN];

int main(){

	ifstream in ("diamond.in");
	ofstream out ("diamond.out");

	in >> N >> K;
	for (int i = 0; i < N; i++)
		in >> ar[i];

	sort(ar, ar+N);

	for(int i = 0, j = 0; i < N; i++){
		if(j == N) {
			bl[i] = j-i;
			continue;
		}
		while(j < N && (j <= i || ar[j]-ar[i] <= K)) j++;
		bl[i] = j-i;
	}
	
	dpr[N-1] = bl[N-1];
	for(int i = N-2; i >= 0; i--)
		dpr[i] = max(dpr[i+1], bl[i]);

	for(int i = N-1, j = N-1; i >= 0; i--){
		if(j == -1){
			br[i] = i-j;
			continue;
		}
		while(j >= 0 && (j >= i || ar[i]-ar[j] <= K)) j--;
		br[i] = i-j;
	}

	dpl[0] = br[0];
	for(int i = 1; i < N; i++)
		dpl[i] = max(dpl[i-1], br[i]);

	int ans = max(dpl[N-1], dpr[0]);
	for (int i = 1; i < N; i++){
		ans = max(ans, dpr[i] + dpl[i-1]);
	}
	out << ans << endl;	

}

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int N, M, D, S, i, j, k, x, y;
int p[1005], m[1005], t[1005], milk[105], goodmilk[105], drank[105][105];
int after[105];
int main(){

	ifstream in ("badmilk.in");
	ofstream out ("badmilk.out");

	in >> N >> M >> D >> S;

	for (i = 0; i < D; i++){		
		in >> p[i] >> m[i] >> t[i];
		if (drank[p[i]][m[i]] == 0){
			milk[m[i]]++;
			drank[p[i]][m[i]] = 1;
		}
	}

	int ind[105];
	for (i = 0; i < S; i++){
		in >> x >> y;
		fill(ind, ind + M+1, 0);
		for (j = 1; j <= M; j++){
			for(k = 0; k < D; k++){				
				if(p[k] == x && t[k] < y && m[k] == j)
					ind[j] = 1;
			}
		}

		for (j = 1; j <= M; j++){
			if(ind[j] = 0)
				goodmilk[j] = 1;
		}
	}

	int ans = 0;
	for(i = 1; i <= M; i++)
		if(goodmilk[i] == 0)
			ans = max(ans, milk[i]);

	out << ans << endl;

	
}

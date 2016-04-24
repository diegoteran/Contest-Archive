#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

typedef pair<int, int> pii;

int f[MAXN][MAXN], r, c, q, t, x, y, acR[MAXN], acC[MAXN];
vector<pii> moves;

int main(){

	cin >> r >> c >> q;
	while (q--){

		cin >> t;
		if (t <= 2){
			cin >> x;
			moves.push_back(make_pair(t, --x));
			continue;
		}
		
		cin >> x >> y >> t;
		x--; y--;
		for (int i = moves.size() - 1;  i >= 0; i--){

			if (moves[i].first == 1 && x == moves[i].second)
				y = (y + 1)%c;
			
			if (moves[i].first == 2 && y == moves[i].second)
				x = (x + 1)%r;
		}
		
		f[x][y] = t;

	}

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (j)
				cout << " ";
			cout << f[i][j];
		}
		cout << endl;
	}	
}

#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;

#define mp make_pair
#define fst first
#define snd second

int T, t, grid[105][105], R, C, W, x, y, i, j, m, n;
stack<pii> s;

int main(){
	scanf("%d", &T);
	for (t = 1; t <= T; t++){
			
		scanf("%d %d %d %d", &R, &C, &m, &n);
		scanf("%d", &W);

		for (i = 0; i < R; i++)
			for (j = 0; j < C; j++)
				grid[i][j] = 0;

		for (i = 0; i < W; i++){
			scanf("%d %d", &x, &y);
			grid[x][y] = -1;
		}

		if (m < n) swap(m, n);
		
		int ansE = 0; int ansO = 0;
		s.push(mp(0, 0));
		while (!s.empty()){
			int count = 0;
					
			pii p = s.top(); s.pop();
			if(grid[p.fst][p.snd] > 0)
				continue;
			grid[p.fst][p.snd] = 1;
			
			if(n == 0){
				if(p.fst + m < R && grid[p.fst+m][p.snd] > -1){
					count++;
					s.push(mp(p.fst+m, p.snd));
				}
				if(p.fst - m >= 0 && grid[p.fst-m][p.snd] > -1){
					count++;
					s.push(mp(p.fst-m, p.snd));
				}
				if(p.snd + m < C && grid[p.fst][p.snd+m] > -1){
					count++;
					s.push(mp(p.fst, p.snd+m));
				}
				if(p.snd - m >= 0 && grid[p.fst][p.snd-m] > -1){
					count++;
					s.push(mp(p.fst, p.snd-m));
				}
			} else {
				if(p.fst + n < R && p.snd + m < C && grid[p.fst+n][p.snd+m] > -1){
					count++;
					s.push(mp(p.fst+n, p.snd+m));
				}
				if(p.fst + n < R && p.snd - m >= 0 && grid[p.fst+n][p.snd-m] > -1){
					count++;
					s.push(mp(p.fst+n, p.snd-m));
				}if(p.fst - n >= 0 && p.snd + m < C && grid[p.fst-n][p.snd+m] > -1){
					count++;
					s.push(mp(p.fst-n, p.snd+m));
				}if(p.fst - n >= 0 && p.snd - m >= 0 && grid[p.fst-n][p.snd-m] > -1){
					count++;
					s.push(mp(p.fst-n, p.snd-m));
				}
				if(n !=m) {
					swap(n, m);
				if(p.fst + n < R && p.snd + m < C && grid[p.fst+n][p.snd+m] > -1){
					count++;
					s.push(mp(p.fst+n, p.snd+m));
				}
				if(p.fst + n < R && p.snd - m >= 0 && grid[p.fst+n][p.snd-m] > -1){
					count++;
					s.push(mp(p.fst+n, p.snd-m));
				}if(p.fst - n >= 0 && p.snd + m < C && grid[p.fst-n][p.snd+m] > -1){
					count++;
					s.push(mp(p.fst-n, p.snd+m));
				}if(p.fst - n >= 0 && p.snd - m >= 0 && grid[p.fst-n][p.snd-m] > -1){
					count++;
					s.push(mp(p.fst-n, p.snd-m));
				}
				}
			}
			if (count%2 == 1)
				ansO++;
			else 
				ansE++;
		}
		printf("Case %d: %d %d\n", t, ansE, ansO);
	}
}

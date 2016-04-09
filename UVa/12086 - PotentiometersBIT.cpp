#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 200010

using namespace std;

int a[MAXN], tree[MAXN], N, x, y, t;
char c[5];

//Fenwick Tree
void update(int idx, int x){

	for (; idx < MAXN; idx += (idx&-idx))
		tree[idx] += x;

}

int query(int idx){
	
	int ans = 0;
	for (; idx > 0; idx -= (idx&-idx))
		ans += tree[idx];
	return ans;

}

int main(){

	while (t++, scanf("%d", &N), N){
		if(t>1)
			printf("\n");
		fill(tree, tree+MAXN, 0);
		for (int i = 1; i <= N; i++){
			scanf("%d", a + i);
			update(i, a[i]);		
		}
		
		printf("Case %d:\n", t);
		while (scanf("%s", c), c[0] != 'E'){
			scanf("%d %d", &x, &y);
			if (c[0] == 'S'){
				update(x, -a[x]);
				update(x, y);
				a[x] = y;
			}	
			else
				printf("%d\n", query(y)-query(x-1));
		}
	}

}

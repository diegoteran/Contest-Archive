#include <cstdio>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define MAXN 600200
#define left (2*node + 1)
#define right (2*node + 2)
#define mp make_pair

int ar[MAXN], N, M, a, b, c, q;
ordered_set t[4*MAXN];

int getVal(int n, int x){
	return t[n].order_of_key(mp(x, 1000000));	
}
	
void update(int x, int y, int lo, int hi, int node){
	if(ar[x])	
		t[node].erase(t[node].find(mp(ar[x], x)));
	t[node].insert(mp(y, x));
	if (hi != lo){
		if (x <= (lo+hi)/2)
			update(x, y, lo, (lo+hi)/2, left);
		else
			update(x, y, (lo+hi)/2+1, hi, right);
	}else
		ar[x] = y;

}

int query (int x, int qlo, int qhi, int lo, int hi, int node){

	if(qlo <= lo && hi <= qhi)
		return getVal(node, x);
	if(hi < qlo || qhi < lo)
		return 0;
	return query(x, qlo, qhi, lo, (lo+hi)/2, left) + query(x, qlo, qhi, (lo+hi)/2+1, hi, right);

}

int main(){

	while( scanf("%d %d", &N, &M) != EOF){	
		fill(ar, ar+MAXN, 0);
		for(int i = 0; i < MAXN*4; i++)
			t[i].clear();
		while (M--){
			scanf("%d", &q);
			if (q) {
				scanf("%d %d %d", &a, &b, &c);
				printf("%d\n", query(c, a, b, 0, N-1, 0));
			} else {
				scanf("%d %d", &a, &b);
				update(a, b, 0, N-1, 0);
			}
		}
	}
}

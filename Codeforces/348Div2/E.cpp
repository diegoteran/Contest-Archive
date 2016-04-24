#include <cstdio>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define MAXN 1000010
#define mp make_pair

ordered_set t[MAXN];
map<int, int> m;

void updateAdd(int idx, int s){
	m[s]++;
	for (; idx < MAXN; idx += (idx&-idx))
		t[idx].insert(mp(s, m[s]));
}

void updateSub(int idx, int s){
	for (; idx < MAXN; idx += (idx&-idx))
		t[idx].erase(mp(s, m[s]));
	m[s]--;
}

int query(int idx, int s){
	int sum = 0;
	for(; idx; idx -= (idx&-idx))
		sum += t[idx].order_of_key(mp(s+1, 0));
	return sum;
}

int N, a, ti, x;

int main(){

	scanf("%d", &N);
	while (N--){
		
		scanf("%d %d %d", &a, &ti, &x);
		if(a == 1)
			updateAdd(ti, x);
		
		if(a == 2)
			updateSub(ti, x);
		
		if(a == 3)
			printf("%d\n", query(ti, x) - query(ti, x-1));
	}
}

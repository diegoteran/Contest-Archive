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

struct query{
	int a, t, x;
};

query q[MAXN];
pii compress[MAXN];
ordered_set t[MAXN], t2[MAXN];
map<int, int> m, m2;

void updateAdd(int idx, int s){
	m[s]++;
	for (; idx < MAXN; idx += (idx&-idx))
		t[idx].insert(mp(s, m[s]));
}

void updateSub(int idx, int s){
	m2[s]++;
	for (; idx < MAXN; idx += (idx&-idx))
		t2[idx].insert(mp(s, m2[s]));
}

int query(int idx, int s){
	int sum = 0;
	for(; idx; idx -= (idx&-idx)){
		sum += (t[idx].order_of_key(mp(s+1, 0)) - t2[idx].order_of_key(mp(s+1,0)));
	}
	return sum;
}

int N, a, ti, x;

int main(){

	scanf("%d", &N);
	for (int i = 0; i < N; i++){		
		scanf("%d %d %d", &q[i].a, &q[i].t, &q[i].x);
		compress[i] = mp(q[i].t, i);
	}
	sort(compress, compress+N);

	for (int i = 0; i < N; i++)
		q[compress[i].second].t = i+1;
	
	for (int i = 0; i < N; i++){
		if(q[i].a == 1)
			updateAdd(q[i].t, q[i].x);
		
		if(q[i].a == 2)
			updateSub(q[i].t, q[i].x);
		
		if(q[i].a == 3)
			printf("%d\n", query(q[i].t, q[i].x) - query(q[i].t, q[i].x-1));
	}
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MAXN 100200
#define mp make_pair
typedef pair<long long, long long> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

long long T, N, Q, p[MAXN], mini[MAXN], c, acum[MAXN];
bool leaf[MAXN];
vector<pii> adj[MAXN];
ordered_set s;

void dfs(int u) {

	if (adj[u].size() == 0) {
		leaf[u] = true;
		return;
	}

	for (auto v : adj[u]) {
		acum[v.first] = acum[u] + 2*v.second - mini[u];
		dfs(v.first);
	}
}

int main(){
	cin >> T;
	while (T--) {
		cin >> N;	
		for (int i = 1; i <= N; i++)
			adj[i].clear();

		fill(mini, mini+MAXN, 200000);
		fill(leaf, leaf+MAXN, false);
		s.clear();		

		for (int i = 2; i <= N; i++){
			cin >> p[i] >> c;
			adj[p[i]].push_back(mp(i, c));
			mini[p[i]] = min(mini[p[i]], c);
		}

		dfs(1);
		
		for (int i = 1; i <= N; i++)
			if (leaf[i])
				s.insert(mp(acum[i], i));

		cin >> Q;
		for (int i = 0; i < Q; i++) {
			cin >> c;
			cout << (long long)s.order_of_key(mp(c+1, 0)) << endl;
		}
			
	}
}

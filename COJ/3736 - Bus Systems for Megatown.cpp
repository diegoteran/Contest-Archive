#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
 
#define MAXN 100010
 
int T, N, M, a, b, dfsNumberCounter, low[MAXN], num[MAXN], p[MAXN], dfsRoot, rootChildren;
bool v[MAXN], flag;
vector<int> adj[MAXN];
 
int dfsConnected(int u){
	int ans = 0;
	if (v[u]) return ans;
	v[u] = true;
	for (int j: adj[u])
		ans += dfsConnected(j);
 
	return ans + 1;
}
 
void articulationPoints(int u){
	low[u] = num[u] = dfsNumberCounter++;
	v[u] = true;
	for (int j: adj[u]) {
		if (!v[j]) {
			p[j] = u;
			if (u == dfsRoot) rootChildren++;
 
			articulationPoints(j);
 
			if (low[j] >= num[u] && u != dfsRoot) {
				flag = true; //AP exists
			}
 
			low[u] = min(low[u], low[j]);
		}
		else if (j != p[u])
			low[u] = min(low[u], num[j]);
	}
}
 
int main() {
 
	scanf("%d", &T);
 
	while (T--){
 
		fill(v, v+MAXN, false);
		for (int i = 0; i < MAXN; i++)
			adj[i].clear();
 
		scanf("%d %d", &N, &M);
 
		for (int i = 0; i < M; i++){
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
 
		if (dfsConnected(1) < N || N <= 2) {
			printf("NO\n");
			continue;
		}
 
		dfsNumberCounter = 0;
		fill(v, v+MAXN, false);
		fill(num, num+MAXN, 0);
		fill(low, low+MAXN, 100000000);
		fill(p, p+MAXN, 0);
		flag = false;
		dfsRoot = 1;
		rootChildren = 0;
		articulationPoints(1);
 
		if (flag || rootChildren > 1)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
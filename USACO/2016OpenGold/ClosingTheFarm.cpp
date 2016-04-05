#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define MAXN 200010

using namespace std;

int N, M, a, b, ls[MAXN], g[MAXN], p[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN], ans[MAXN];

//union-find
int id(int x){
	if (p[x] == x)
		return x;
	return p[x] = id(p[x]);
}

void join(int a, int b){
	a = id(a);
	b = id(b);
	
	if(a != b){
		g[a] += g[b];
		p[b] = a;
	}
}

int main(){

	ifstream in ("closing.in");
	ofstream out ("closing.out");

	for (int i = 0; i < MAXN; i++){
		p[i] = i;
		g[i] = 1;
	}

	in >> N >> M;
	while (M--){
		in >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i < N+1; i++)
		in >> ls[i];

	reverse(ls+1, ls+N+1);
	
	visited[ls[1]] = ans[1] = true;
	for (int i = 2; i <= N; i++){
		int v = ls[i];
		visited[v] = true;
		for (int k = 0; k < adj[v].size(); k++){
			if (visited[adj[v][k]])
				join(v, adj[v][k]);
		}
		ans[i] = g[id(v)] == i;
	}

	reverse(ans+1, ans+N+1);

	for (int i = 1; i <= N; i++)
		out << (ans[i] ? "YES" : "NO") << endl;

}

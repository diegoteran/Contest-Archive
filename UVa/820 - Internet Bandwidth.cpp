#include <cstdio>
#include <algorithm>
#include <queue>

#define MAXN 200
#define INF 100000000

using namespace std;

int N, M, T, s, t, f, flow[MAXN][MAXN];

//Build graph
struct edge{
	int node, next;
};

edge graph[MAXN*MAXN];
int start[MAXN], nextEdge, p[MAXN];
bool v[MAXN];
queue<int> q;

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

void init(){
	fill(start, start+MAXN, 0);
	fill(v, v+MAXN, false);
	nextEdge = 1;
	for (int i = 0; i < MAXN; i++)
		for( int j = 0; j < MAXN; j++)
			flow[i][j] = 0;
}

void augment(int u, int minEdge){
	if (u == s) {f = minEdge; return; }
	if (p[u]) {
		augment(p[u], min(minEdge, flow[p[u]][u]));
		flow[p[u]][u] -= f;
		flow[u][p[u]] += f;
	}
}

int edmondsKarp(){

	int mf = 0;
	do {
		f = 0;
		fill(v, v+MAXN, false);
		fill(p, p+MAXN, 0);
		while (!q.empty()) q.pop();
		q.push(s); v[s] = true;
		while (!q.empty()){

			int u = q.front(); q.pop();
			if(u == t) break;

			for (int k = start[u]; k; k = graph[k].next)
				if (flow[u][graph[k].node] > 0 && !v[graph[k].node]){
					q.push(graph[k].node);
					p[graph[k].node] = u;
					v[graph[k].node] = true;
				}
		}
		
		augment(t, INF);
		mf += f;

	} while (f != 0);

	return mf;

}

int main(){
	
	int a, b, c;
	while (scanf("%d", &N), T++, N){
		
		init();
		scanf("%d %d %d", &s, &t, &M);
		while (M--){
			scanf("%d %d %d", &a, &b, &c);
			if (!flow[a][b]) {addEdge(a, b); addEdge(b, a);}
			flow[a][b] += c;
			flow[b][a] += c;
		}

		printf("Network %d\nThe bandwidth is %d.\n\n", T, edmondsKarp());

	}

}

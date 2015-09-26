#include <cstdio>
#include <algorithm>
#include <vector>

#define MAXN 105
#define MAXM 10005

using namespace std;

struct edge{
	int node, next;
};

int start[MAXN], nextEdge;
edge graph[MAXM];
bool visited[MAXN];

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

void init(){
	nextEdge = 1;
	fill(start, start+MAXN, 0);
	fill(visited, visited+MAXN, false);
}

int N, M, i, j, x, y;
vector<int> ts;

void dfs2(int u){
	visited[u] = true;

	for (int v = start[u]; v; v = graph[v].next)
		if(!visited[graph[v].node])
			dfs2(graph[v].node);

	ts.push_back(u);
}

int main(){
	while (scanf("%d %d", &N, &M), N+M){
	
		init();
		ts.clear();
		for (i = 0; i < M; i++){
			scanf("%d %d", &x, &y);
			addEdge(x, y);
		}
		
		for (i = 1; i <= N; i++)
			if(!visited[i])
				dfs2(i);

		for (i = ts.size()-1; i >= 0; i--)
			printf("%d%c", ts[i], (i ? ' ' : '\n'));
	}
}



























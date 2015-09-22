#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

#define MAXN 205
#define MAXM 40005

int N, M, i, j, x, y;

struct edge{
	int next, node;
};

int start[MAXN], nextEdge, color[MAXN];
edge graph[MAXM];

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

void init(){
	nextEdge = 1;
	fill(start, start+MAXN, 0);
	fill(color, color+MAXN, 0);
}

stack<int> s;
bool dfs(int u){
	while (!s.empty()) s.pop();

	s.push(u); color[u] = 1;

	bool isBipartite = true;

	while (!s.empty() && isBipartite){
		int v = s.top(); s.pop();

		for (int k = start[v]; k; k = graph[k].next){
			if(!color[graph[k].node]){
				color[graph[k].node] = 3 - color[v];
				s.push(graph[k].node);
			} else if(color[graph[k].node] == color[v]){
				isBipartite = false;
				break;
			}
		}
	}

	return isBipartite;
}

int main(){

	while(scanf("%d", &N), N){

		init();
		scanf("%d", &M);
		for (i = 0; i < M; i++){
			scanf("%d %d", &x, &y);
			addEdge(x, y);
			addEdge(y, x);
		}

		printf("%s\n", (dfs(0) ? "BICOLORABLE." : "NOT BICOLORABLE."));
			
	}
}

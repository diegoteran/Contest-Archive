#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define fst first
#define snd second
#define mp make_pair
#define MAXN 1005
#define MAXM 1000005

using namespace std;

typedef pair<int, int> pii;

struct edge{
	int next, node, cost;
};

int start[MAXN], nextEdge;
edge graph[MAXM];
bool visited[MAXN];
long long int dist[MAXN];
priority_queue<pii, vector<pii>, greater<pii> > q;
vector<int> ts;

//Create graph
void addEdge(int a, int b, int c){
	graph[nextEdge].cost = c;
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

void init(){
	nextEdge = 1;
	fill(dist, dist+MAXN, -1);
	fill(start, start+MAXN, 0);
	fill(visited, visited+MAXN, false);
}

//Dijkstra
void dijkstra(int u){
	
	q.push(mp(0, u));

	while(!q.empty()){

		pii p = q.top(); q.pop();
		if(visited[p.snd]) continue;
		visited[p.snd] = true;

		dist[p.snd] = p.fst;

		for (int v = start[p.snd]; v; v = graph[v].next)
			if(!visited[graph[v].node])
				q.push(mp(p.fst + graph[v].cost, graph[v].node));

	}

}

//Topological sort
void dfs2(int u){
	visited[u] = true;

	for(int v = start[u]; v; v = graph[v].next)
		if(dist[u] > dist[graph[v].node] && !visited[graph[v].node])
			dfs2(graph[v].node);

	ts.push_back(u);
}

//Variables
int N, M, i, j, x, y, z;
long long int dp[MAXN];

//Adjacency Matrix
int path[MAXN][MAXN];

int main(){
	while (scanf("%d", &N), N){
		scanf("%d", &M);
		init();
		ts.clear();
		for (i = 0; i < MAXN; i++)
			for (j = 0; j < MAXN; j++)
				path[i][j] = 0;
		for (i = 0; i < M; i++){
			scanf("%d %d %d", &x, &y, &z);
			addEdge(x, y, z);
			addEdge(y, x, z);
			path[x][y]++; path[y][x]++;
		}

		dijkstra(2);

	//	for (i = 1; i <= N; i++)
	//		printf("%d: %lld\n", i, dist[i]);

		if(dist[1] == -1){
			printf("0\n");
			continue;
		}
		
		fill(visited, visited+MAXN, false);
		dfs2(1);
	//	for (i = 0; i < ts.size(); i++)
	//		printf("%d\n", ts[i]);
	//	printf("\n");
		
		//Finishing DP
		fill(dp, dp+MAXN, 0);
		dp[0] = 1;
		for (i = 1; i < ts.size(); i++){			
			for (j = i-1; j >= 0; j--){
	//			printf("Enters for: %d %d\n", j, ts[j]);
				if(path[ts[i]][ts[j]] && dist[ts[i]] > dist[ts[j]]){
					dp[i] += dp[j]*path[ts[i]][ts[j]];
	//				printf("Enters if: %d %lld\n", j, dp[j]);	
				}
			}
		}
	
		printf("%lld\n", dp[ts.size()-1]);

	}
}











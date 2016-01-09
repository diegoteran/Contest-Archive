/* TIME LIMIT */


#include <cstdio>
#include <algorithm>

using namespace std;

//Graph
struct edge{
	int node, next;
};

edge graph[50100];
int nextEdge, start[50100];
bool visited[50100];

void init(){
	nextEdge = 1;
	fill(start, start + 50100, 0);
}

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int T, t, N, a, b, i, j, v, answ, temp, winner;

int dfs(int u){
	
	int ans = 0;
	
	if(visited[u]) return 0;
	visited[u] = true;

	for(v = start[u]; v; v = graph[v].next)
		ans  = max(ans, dfs(graph[v].node) + 1);
	
	return ans;
}

int main(){

	scanf("%d", &T);
	for(t = 1; t <= T; t++){
		
		init();
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%d %d", &a, &b);
			addEdge(a, b);
		}
		
		answ = 0;
		
		for(i = 1; i <= N; i++){
			fill(visited, visited + 50100, false);
			temp = dfs(i);
		//	printf("%d %d\n", i, temp);
			if(answ < temp){
				answ = temp;
				winner = i;
			}
		}

		printf("Case %d: %d\n", t, winner);
	}

}

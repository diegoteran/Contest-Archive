#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

#define mp make_pair
#define fst first 
#define snd second 
#define MAXN 20005
#define MAXM 50005

int T, N, M, s, t, x, y, w, i, j;

struct edge{
	int node, next, cost;
};

int start[MAXN], nextEdge;
bool v[MAXN];
edge graph[MAXM];

void addEdge(int a, int b, int c){
	graph[nextEdge].cost = c;
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

priority_queue<pii, vector<pii>, greater<pii> > q;
void init(){
	nextEdge = 1;
	fill(start, start+N, 0);
	fill(v, v+N, false);
}

int dijkstra(int u){

	q = priority_queue< pii, vector<pii>, greater<pii> >();

	q.push(mp(0, u));
	
	while(!q.empty()){
		pii p = q.top(); q.pop();
		if (v[p.snd]) continue;
		v[p.snd] = true;

		if(p.snd == t)
			return p.fst;

		for(int k = start[p.snd]; k; k = graph[k].next){
			if(!v[graph[k].node])
				q.push(mp(p.fst + graph[k].cost, graph[k].node));
		}
	}

	return -1;
}


int main(){
	int tc = 0;
	scanf("%d", &T);
	while (tc++, T--){
		init();
		scanf("%d %d %d %d", &N, &M, &s, &t);
		for (i = 0; i < M; i++){
			scanf("%d %d %d", &x, &y, &w);
			addEdge(x, y, w);
			addEdge(y, x, w);
		}

		x = dijkstra(s);
		if(x == -1)
			printf("Case #%d: unreachable\n", tc);
		else
			printf("Case #%d: %d\n", tc, x);
	}


}

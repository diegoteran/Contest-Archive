#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 10005
#define MAXM 100005

int N, M, T, i, x, y, r, p[MAXN];




//Union-Find
int id(int x){
	if (p[x] == x)
		return x;
	return p[x] = id(p[x]);
}

void join(int a, int b){
	p[id(a)] = id(b);
}




//Graph
struct edge{
	int node, next;
};

edge graph[MAXM];
int start[MAXN], nextEdge;

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}




//Tarjan
int dfsLow[MAXN], dfsNum[MAXN];
vector<int> S;
bool v[MAXN];
int dfsCounter, numSCC;

void init(){
	nextEdge = 1;
	fill(start, start+MAXN, 0);
}

void tarjanSCC(int u){
	
	dfsLow[u] = dfsNum[u] = dfsCounter++;
	S.push_back(u);
	v[u] = true;
	
	for (int j = start[u]; j; j = graph[j].next){
		
		if(dfsNum[graph[j].node] == -1)
			tarjanSCC(graph[j].node);
		
		if(v[graph[j].node])
			dfsLow[u] = min(dfsLow[u], dfsLow[graph[j].node]);
		
	}
	
	if (dfsLow[u] == dfsNum[u]){
		//printf("SCC %d:", ++numSCC);
		numSCC++;
		while(true){
			x = S.back(); S.pop_back(); v[x] = false;
			//printf(" %d", x);
			join(x, u);
			if (u == x) break;
		}
		//printf("\n");
	}
	
}




int used[MAXN], ans, in[MAXM], out[MAXM], t;

int main() {
	
	scanf("%d", &T);
	while (t++, T--){
		
		
		scanf("%d %d", &N, &M);
		init();
		fill(dfsLow, dfsLow+MAXN, 0);
		fill(dfsNum, dfsNum+MAXN, -1);
		fill(v, v+MAXN, false);
		
		for (i = 0; i <= N; i++)
			p[i] = i;
		
		for (i = 0; i < M; i++){
			scanf("%d %d", &x, &y);
			addEdge(x, y);
			in[i] = y;
			out[i] = x;
		}
		
		dfsCounter = numSCC = 0;
		
		for (i = 1; i <= N; i++)
			if (dfsNum[i] == -1)
				tarjanSCC(i);
		
		fill(used, used+MAXN, 0);
		ans = 0;
		for	(i = 0; i < M; i++){
			y = in[i];
			x = out[i];
			if(used[id(y)] == 0 && (id(x) != id(y)))
				used[id(y)]++;
		}
		for	(i = 1; i <= N; i++)
			if (used[id(i)] == 0){
				ans++;
				used[id(i)]++;
			}
		
		printf("Case %d: %d\n", t, ans);
		
	}
	
}
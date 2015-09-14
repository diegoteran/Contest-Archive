#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 2005
#define MAXM 4000005

int N, M, i, x, y, r;

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
			if (u == x) break;
		}
		//printf("\n");
	}
	
}

int main() {
	
	while (scanf("%d %d", &N, &M), N+M != 0){
		
		init();
		fill(dfsLow, dfsLow+MAXN, 0);
		fill(dfsNum, dfsNum+MAXN, -1);
		fill(v, v+MAXN, false);
		
		for (i = 0; i < M; i++){
			scanf("%d %d %d", &x, &y, &r);
			addEdge(x, y);
			if(r == 2) addEdge(y, x);
		}
		
		dfsCounter = numSCC = 0;
		
		for (i = 1; i <= N; i++)
			if (dfsNum[i] == -1)
				tarjanSCC(i);
		
		printf("%d\n", 1 - (numSCC == 1 ? 0: 1));
		
	}
	
}
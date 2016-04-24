#include <bits/stdc++.h>
using namespace std;

#define MAXN 110

struct edge{
	int node, next;
};

edge graph[MAXN*MAXN];
int start[MAXN], nextEdge, N, p[MAXN], num[MAXN], low[MAXN], dfsCounter, rootChildren, aux;
bool used[MAXN][MAXN], v[MAXN], artP[MAXN];
vector<int> t;

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

void init(){
	nextEdge = 1;
	fill(start, start+MAXN, 0);
	fill(v, v+MAXN, false);
	fill(artP, artP+MAXN, false);
	dfsCounter = 0;
	rootChildren = 0;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			used[i][j] = false;
}

void findAP(int u){
	num[u] = low[u] = dfsCounter++;
	v[u] = true;
	for (int k = start[u]; k; k = graph[k].next){
	
		if(!v[graph[k].node]){
			p[graph[k].node] = u;
			if(u == 1) rootChildren++;	

			findAP(graph[k].node);
			
			if (low[graph[k].node] >= num[u])
				artP[u] = true;
				
			low[u] = min(low[u], low[graph[k].node]);
		} 
		else if (graph[k].node != p[u])
			low[u] = min(low[u], num[graph[k].node]);
	}
}

int main() {
	
	while (scanf("%d", &N), N){
		init();
		string str;
		getline(cin, str);
		while(true){
			getline(cin, str);
			string buf; // Have a buffer string
			stringstream ss(str); // Insert the string into a stream
			t.clear(); // Create vector to hold our numbers
			
			while (ss >> buf){
				istringstream(buf) >> aux; //convert string to int
				t.push_back(aux);
			}
			
			if (str[0] != '0'){
				for (int i = 1; i < t.size(); i++){
					if (!used[t[0]][t[i]]){
						addEdge(t[0], t[i]);
						addEdge(t[i], t[0]);
						used[t[0]][t[i]] = used[t[i]][t[0]] = true;
					}
				}
			}
			else{
				int ans = 0;
				findAP(1);
				artP[1] = rootChildren > 1;
				for (int i = 1; i <= N ; i++)
					ans += artP[i];
				printf("%d\n", ans);
				break;
			}
		}
	}
}

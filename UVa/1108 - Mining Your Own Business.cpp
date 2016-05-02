#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>

using namespace std;

#define MAXN 100010

typedef pair<int, int> pii;

struct edge{
	int node, next;
};

edge graph[MAXN];
int start[MAXN], p[MAXN], num[MAXN], low[MAXN], nextEdge, N, root, children, dfsCounter, M;
bool v[MAXN], artP[MAXN];
vector<set<int> > bC;
vector<set<int> > cc;
stack<pii> s;

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

void init(){
	fill(start, start+MAXN, 0);
	fill(v, v+MAXN, false);
	fill(artP, artP+MAXN, false);
	bC.clear();
	cc.clear();
	dfsCounter = 0;
	nextEdge = 1;
}

void findBC(int x){
	low[x] = num[x] = dfsCounter++;
	v[x] = true;
	for (int u = start[x]; u; u = graph[u].next){
		if (!v[graph[u].node]){
			p[graph[u].node] = x;
			if (x == root) children++;
			s.push(make_pair(x, graph[u].node));
			findBC(graph[u].node);
			if ((x != root && low[graph[u].node] >= num[x]) || (x == root && children > 1)){
				artP[x] = true;
				set<int> aux;
				set<int> aux2;
				while(s.top() != make_pair(x, graph[u].node)){
					if(!artP[s.top().first]){
						aux.insert(s.top().first);
					} else
						aux2.insert(s.top().first);
					if(!artP[s.top().second]){
						aux.insert(s.top().second);
					} else
						aux2.insert(s.top().second);
					s.pop();
				}
				if(!artP[s.top().first]){
					aux.insert(s.top().first);
				} else
					aux2.insert(s.top().first);
				if(!artP[s.top().second]){
					aux.insert(s.top().second);
				} else
					aux2.insert(s.top().second);
				s.pop();
				if(aux.size()){
					bC.push_back(aux);
					cc.push_back(aux2);
				}
			}

			low[x] = min(low[graph[u].node], low[x]);			
		} else{
			if (graph[u].node != p[x])
				low[x] = min(low[x], num[graph[u].node]);
		}
	}
}

int main(){
	int t = 0;
	while(t++, scanf("%d", &N), N){
	
		init();
		int a, b;
		long long ans, numb, r;
		M  = numb = 0;
		ans = 1;
		for (int i = 0; i < N; i++){
			scanf("%d %d", &a, &b);
			addEdge(a, b); M = max(M, max(a, b));
			addEdge(b, a);
		}

		root = 1; 
		children = dfsCounter = r = 0;
		findBC(1);
		if(children > 1) artP[1] = true;
		set<int> aux, aux2;
		while(!s.empty()){
			if(!artP[s.top().second])
				aux.insert(s.top().second);
			else
				aux2.insert(s.top().second);
			if(!artP[s.top().first])
				aux.insert(s.top().first);
			else	
				aux2.insert(s.top().first);
			s.pop();
		}
		if(aux.size()){
			bC.push_back(aux);
			cc.push_back(aux2);
		}
		if(bC.size() == 1){
			if(bC[0].size()%2)
				ans *= (bC[0].size()-1)/2*bC[0].size();
			else
				ans *= bC[0].size()/2*(bC[0].size()-1);
			numb += 2;
		}
		if(bC.size() > 1){
			r = 1;
			for (int j = 0; j < bC.size(); j++){
				if(cc[j].size()==1){
					r *= bC[j].size();
					numb ++;
				}
			}
			ans *= r;
		}
		
		printf("Case %d: %lld %lld\n", t, numb, ans);
		
	}
}

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;
#define MAXN 30
#define MAXM 900

struct edge{
	int node, next;	
};

map<char, int> m;
int T, N, i, j, start[MAXN], nextEdge;
edge graph[MAXM];
char x, y;

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

bool v[MAXN];
void init(){
	fill(v, v+MAXN, false);
	nextEdge = 1;
	fill(start, start + MAXN, 0);
}

stack<int> s;
void dfs(int u){
	s.push(u);

	while (!s.empty()){
		
		int k = s.top(); s.pop();
		if (v[k]) continue;
		v[k] = true;

		for(j = start[k]; j; j = graph[j].next){
			if(!v[graph[j].node])
				s.push(graph[j].node);
		}

	}
}

int main(){
	string str;
	for (i = 0; i <=25; i++)
		m['A'+i] = i;

	cin >> T;
	getline(cin, str); getline(cin, str);
	while (T--){
		
		init();
		getline(cin, str);
		char h = str[0];		
		while(getline(cin, str), !str.empty()){
			x = str[0]; y = str[1];
			addEdge(m[x], m[y]);
			addEdge(m[y], m[x]);			
		}
			
		int CC = 0;
	
		for(i = 0; i < h-'A'+1; i++){
			
			if(!v[i]){
				dfs(i); CC++;
			}
		}
		cout << CC << endl;
		if(T) cout << endl;
	}
}

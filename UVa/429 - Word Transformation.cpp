#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;
#define MAXN 205
#define MAXM 40005

int T, N, x, y, i, j, dist[MAXN];

struct edge{
	int node, next;
};

int start[MAXN], nextEdge;
edge graph[MAXM];
bool v[MAXN];

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

void init(){
	nextEdge = 1;
	fill(start, start+MAXN, 0);
}

bool comp(string a, string b){
	if(a.size() != b.size()) return false;
	int r = 0;
	for(int k = 0; k < a.size(); k++)
		if(a[k] != b[k])
			r++;
	if (r > 1)
		return false;
	return true;
}

string words[MAXN];
map<string, int> m;
queue<int> q;
int bfs(int u, int f){

	while(!q.empty()) q.pop();

	q.push(u);
	//cout << "DENTRO BFS: " << endl;
	while(!q.empty()){

		int k = q.front(); q.pop();
		//cout << k << " " << words[k] << " " << dist[k] << " " << v[k] << endl;
		if(v[k]) continue;
		v[k] = true;

		if(k == f)
			return dist[f];
		
		for(int h = start[k]; h; h = graph[h].next)
			if(!v[graph[h].node] && dist[graph[h].node] == 0){
				dist[graph[h].node] = dist[k] + 1;
				q.push(graph[h].node);
			}

	}

}

int main(){
	int count;
	string str;
	cin >> T;
	while (T--){
		init();
		count = 0;
		//cout << "NODOS: " << endl;
		while (cin >> str, str[0] != '*'){
			words[count] = str;
			m[str] = count++;
			//cout << str << " " << count << endl;
		}
		//cout << "ARISTAS: " << endl;
		for (i = 0; i < count; i++)
			for(j = i+1; j < count; j++)
				if(comp(words[i], words[j])){
					addEdge(i, j);
					addEdge(j, i);
					//cout << words[i] << " " << words[j] << endl;
				}
		
		getline(cin, str);
		string s1, s2;
		//cout << "BUSQUEDAS: " << endl;
		while(getline(cin, str), !str.empty()){
			fill(dist, dist+MAXN, 0);
			fill(v, v+MAXN, false);
			stringstream ss(str);
			ss >> s1;
			ss >> s2;
			//cout << s1 << " " << m[s1] << " " << words[m[s1]] << endl;
			//cout << s2 << " " << m[s2] << " " << words[m[s2]] << endl;
			
			cout << s1 << " " << s2 << " " << bfs(m[s1], m[s2]) << endl;	
		}
		if(T!=0)
		cout << endl;
	}

}

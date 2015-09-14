#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
    
#define MAXV 3005
#define MAXE 9000000
#define mp make_pair
#define fst first
#define snd second

struct edge{
    int node, next, weight;
};

edge graph[MAXE];
int start[MAXV], nextEdge;
bool v[MAXV];

void addEdge(int a, int b, int r){
    graph[nextEdge].node = b;
    graph[nextEdge].next = start[a];
    graph[nextEdge].weight = r;
    start[a] = nextEdge++;
}

void init(){
    nextEdge = 1;
    fill(start, start+MAXV, 0);
    fill(v, v+MAXV, false);
}

int V, E, x, y, w, s, i;
priority_queue<pii, vector<pii>, greater<pii>> q;

int main() {
    
    init();
    cin >> V >> E;
    for (i = 0; i < E; i++){
        cin >> x >> y >> w;
        addEdge(x, y, w);
        addEdge(y, x, w);
    }
    
    cin >> s;
    q.push(mp(0,s));
    int d = 0;
    while (!q.empty()){
        
        pii curr = q.top(); q.pop();
        if (v[curr.snd]) continue;
        v[curr.snd] = true;
        
        d += curr.fst;
        
        for (x = start[curr.snd]; x; x = graph[x].next)
            if(!v[graph[x].node])
                q.push(mp(graph[x].weight, graph[x].node));
        
    }
    
    cout << d << endl;
    
}

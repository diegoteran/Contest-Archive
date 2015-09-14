#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

#define MAXN 3005
#define MAXM 9000000
#define INF 99999999999999999


struct edge{
    int node, next, weight;
};

edge graph[MAXM];
long long start[MAXN], nextEdge, T, V, E, a, b, r, x, s, i, d[MAXN];
bool visited[MAXN];

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;



void init(){
    nextEdge = 1;
    fill(start, start+MAXN, 0);
    fill(d, d+MAXN, INF);
    fill(visited, visited+MAXN, false);
}

void addEdge(int a, int b, int r){
    graph[nextEdge].node = b;
    graph[nextEdge].next = start[a];
    graph[nextEdge].weight = r;
    start[a] = nextEdge++;
}



int main() {
    
    cin >> T;
    while (T--){
        
        init();
        
        cin >> V >> E;
        for (i = 0; i < E; i++){
            cin >> a >> b >> r;
            addEdge(a,b,r);
            addEdge(b,a,r);
        }
        
        cin >> s;
        //for(i = 1; i <= V; i++)
            //q.push(i);
        q.push(make_pair(0, s));
        
        
        while (!q.empty()){
            
            pair<int, int> pi = q.top();
            q.pop();
            if(visited[pi.second]) continue;
            visited[pi.second] = true;
            
            d[pi.second] = pi.first;
            
            for (x = start[pi.second]; x; x = graph[x].next){
                
                if(!visited[graph[x].node])
                    q.push(make_pair(pi.first + graph[x].weight, graph[x].node));
                                                                    
            }
            
        }
        
        for (i = 1; i <= V; i++){
            if(i == s)
                continue;
            if(i == V || (i==V-1 && s==V))
                cout << (visited[i] ? d[i] : -1) << endl;
            else
                cout << (visited[i] ? d[i] : -1) << " ";           
        }
        
    }
    
}

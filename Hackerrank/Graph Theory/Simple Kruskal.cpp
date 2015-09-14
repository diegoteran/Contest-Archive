#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXV 3005
#define MAXE 9000000
#define mp make_pair
#define snd second
#define fst first

typedef pair<int, pair<int, int>> edge;

int V, E, x, y, r, s, i;
int p[MAXV];
edge edges[MAXE];

int id(int x){
    if(p[x] == x)
        return x;
    return p[x] = id(p[x]);
}

void join(int a, int b){
    p[id(a)] = id(b);
}

int main() {
    
    cin >> V >> E;
    
    for (i = 1; i <= V; i++)
        p[i] = i;
    
    for (i = 0; i < E; i++){
        cin >> x >> y >> r;
        edges[i] = mp(r, mp(x,y));
    }
    
    sort(edges, edges+E);
    
    long long ans = 0;
    int components = V;
    
    for(i = 0; i < E; i++){  
        int a = id(edges[i].snd.fst);
        int b = id(edges[i].snd.snd);
        if(a != b){
            join(a, b);
            ans += edges[i].fst;
            components--;
        }
    }
    
    cout << ans << endl;
    
}

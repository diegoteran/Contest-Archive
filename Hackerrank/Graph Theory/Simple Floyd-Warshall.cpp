#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 9999999999999999
#define MAXV 405
#define MAXE 160000

long long dist[MAXV][MAXV];
int N, M, x, y, r, Q, i, j ,k; 

int main() {
    
    fill(dist[0], dist[0]+MAXV*MAXV, INF);
    
    scanf("%d %d", &N, &M);
    
    for(i = 1; i <= N; i++)
        dist[i][i] = 0;
    
    for (i = 0; i < M; i++){
        scanf("%d %d %d", &x, &y, &r);
        dist[x][y] = r;
    }
    
    for (k = 1; k <= N; k++)
        for (i = 1; i <= N; i++)
            for (j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        
    scanf("%d", &Q);
    for (i = 0; i < Q; i++){
        scanf("%d %d", &x ,&y);
        printf("%lld\n", (dist[x][y] != INF ? dist[x][y]: -1));
    }       
    
}

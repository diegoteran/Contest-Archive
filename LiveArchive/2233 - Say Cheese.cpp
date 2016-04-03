#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

#define INF 1e15
#define MAXN 110
#define MAXM (110*110)

double X[MAXN], Y[MAXN], Z[MAXN], R[MAXN];
int N, t;

double sq(double a){
	return a*a;
}

double dist(int a, int b) {
	return sq(X[a]-X[b]) + sq(Y[a] - Y[b]) + sq(Z[a] - Z[b]);
}

struct edge{
	int node, next;
	double weight;
};

int start[MAXN], nextEdge;
edge graph[MAXM];
bool visited[MAXN];
double distan[MAXN];

void init(){
	nextEdge = 1;
	fill(start, start+MAXN, 0);
	fill(visited, visited+MAXN, false);
	fill(distan, distan+MAXN, INF);
}

void addEdge(int a, int b, int c){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	graph[nextEdge].weight = c;
	start[a] = nextEdge++;
}

priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > q;

void dijkstra(){
	
	while (!q.empty()){

		pair<double, int> curr = q.top(); q.pop();
		if (visited[curr.second]) continue;
		visited[curr.second] = true;

		distan[curr.second] = curr.first;
		if (curr.second == N+1) break;

		for (int k = start[curr.second]; k; k = graph[k].next){
			if (!visited[graph[k].node])
				q.push(make_pair(distan[curr.second] + graph[k].weight, graph[k].node));
		}

	}

}

int main(){

	while (t++, scanf("%d", &N), N != -1) {
		
		init();
		for (int i = 0; i < N; i++)
			scanf("%lf %lf %lf %lf", &X[i], &Y[i], &Z[i], &R[i]);
		scanf("%lf %lf %lf", &X[N], &Y[N], &Z[N]); R[N] = 0;
		scanf("%lf %lf %lf", &X[N+1], &Y[N+1], &Z[N+1]); R[N+1] = 0;

		
		for (int i = 0; i <= N; i++)
			for (int j = i+1; j <= N+1; j++){
				if (dist(i, j) <= R[i] + R[j]){
					addEdge(i, j, 0);
					addEdge(j, i, 0);
				}
				else {
					addEdge(j, i, sqrt(dist(i, j)) - R[i] - R[j]);
					//double x = dist(i, j);
					//printf("Dist entre %d y %d : %lf\n", i, j, x);
					addEdge(i, j, sqrt(dist(i, j)) - R[i] - R[j]);
				}
			}
	
		while (!q.empty()) q.pop();
		q.push(make_pair(0.0, N));
		dijkstra();

		printf("Cheese %d: Travel time = %d sec\n", t, (int)round(10*distan[N + 1]));

	}


}

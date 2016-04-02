#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

#define INF 1e8

int adj[60][60];
int P, R, t;
map<string, int> m;
string a, b;


int main(){

	while (t++, scanf("%d %d", &P, &R), P+R){
		int cu = 1;
		m.clear();
		for(int i = 0; i < 60; i++)
			for (int j = 0; j < 60; j++)
				adj[i][j] = INF;
		while (R--){
					
			cin >> a >> b;
			
			if (!m[a])			
				m[a] = cu++;
			
			if (!m[b])
				m[b] = cu++;

			adj[m[a]][m[b]] = adj[m[b]][m[a]] = 1;			
			
		}

		for (int k = 1; k <= P; k++)
			for (int i = 1; i <= P; i++)
				for (int j = 1; j <= P; j++)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

		int ans = 0;
		
		for(int i = 1; i <= P; i++)
			for (int j = 1; j <= P; j++)
				if (i != j)
					ans = max(ans , adj[i][j]);

		printf("Network %d: ", t);
		if (ans < INF)
			printf("%d\n\n", ans);
		else
			printf("DISCONNECTED\n\n");
	}

}

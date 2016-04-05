#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, a, b, visited[3010], used[3010];
vector<int> adja[3010];

int dfs(int x){

	if(visited[x] || used[x]) return 0;
	visited[x] = 1;

	int ans = 1;
	for (int i = 0; i < adja[x].size(); i++)
		if (!used[adja[x][i]])
			ans += dfs(adja[x][i]);

	return ans;

}

int main(){

	ifstream in ("closing.in");
	ofstream out ("closing.out");

	in >> N >> M;
	while (M--){
		in >> a >> b;
		adja[a].push_back(b);
		adja[b].push_back(a);
	}

	out << (dfs(1) == N ? "YES" : "NO") << endl;

	for (int i = 1, j; i < N; i++){
		in >> a;
		used[a]++;
		for (j = 1; j <= N; j++){
			if (!used[j])
				break;
		}
		fill(visited+1, visited+N+1, 0);
		out << ((dfs(j) == N-i) ? "YES" : "NO") << endl;
	}
	in >> a;

}

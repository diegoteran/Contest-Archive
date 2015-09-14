#include <cstdio>
#include <map>

using namespace std;

int N, M;
map<int, int> cd;

int main() {
	int i, j;
	while (scanf("%d %d", &N, &M), N + M){
		cd.clear();
		
		for (i = 0; i < N; i++){
			scanf("%d", &j);
			if(cd[j] < 1)
				cd[j]++;
		}
		for (i = 0; i < M; i++){
			scanf("%d", &j);
			cd[j]++;
		}
		
		j = 0;
		for (map<int, int>::iterator it = cd.begin(); it != cd.end(); it++)
			if( it->second > 1)
				j++;
			
		printf("%d\n", j);
		
	}
	
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

#define mp make_pair
typedef pair<int, int> pii;

string names[4000];
int times[4000];
priority_queue<pii, vector<pii>, greater<pii> > q;

int main() {
	int T, n, k;
	scanf("%d", &T);
	while(T--){
		while (!q.empty()) q.pop();
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			cin >> names[i] >> times[i];
			q.push(mp(times[i], i));
		}

		for (int i = 0; i < k; i++) {
			pii t = q.top();
			q.pop();
			cout << t.first << " " << names[t.second] << endl;
			q.push(mp(t.first + times[t.second], t.second));
		}
	}
}

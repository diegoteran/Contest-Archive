#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define MAXN 100100
#define mp make_pair
#define fst first
#define snd second


typedef long long ll;
typedef pair<int, int> pii;

pii p[2*MAXN];
ll n[MAXN];
map<ll, ll> c, sp;
vector<pii> m;
vector<int> v[MAXN];

int main(){
	int N, M, K, a, b;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &a, &b);
		n[a]++;
		p[i] = mp(a, b);
	}

	ll ans = 0;
	for (ll i = 1; i <= N; i++) {
		
		if ( n[i]*n[i] < K ) continue;
	
//		printf("Node %lld is fat.\n", i);
		sp.clear();
		for (ll j = 0; j < K; j++)
			if (p[j].fst == i)
				sp[p[j].snd]++;

		c.clear();
		for (ll j = 0; j < K; j++) {
			if (p[j].fst <= i && n[p[j].fst]*n[p[j].fst] >= K) continue;
			c[p[j].fst] += sp[p[j].snd];
		}

		for (map<ll, ll>::iterator t = c.begin(); t != c.end(); t++)
			if (t->snd > 1)
				ans += (t->snd)*(t->snd - 1)/2;
	}

	for (ll i = 0; i < K; i++)
		if (n[p[i].fst]*n[p[i].fst] < K)
			v[p[i].fst].push_back(p[i].snd);

	for (ll i = 1; i <= N; i++)
		if (n[i]*n[i] < K)
			for (ll j = 0; j < v[i].size(); j++)
				for (ll u = j+1; u < v[i].size(); u++)
					if (v[i][j] > v[i][u]) 
						m.push_back(mp(v[i][u], v[i][j]));
					else
						m.push_back(mp(v[i][j], v[i][u]));
	
	printf("Yay1\n");
	sort(m.begin(), m.end());
	ll r = 1;
	printf("YaySort\n");
	for (ll i = 0; i < m.size()-1; i++) {
		printf("Yay ?\n");
		fflush(stdout);
		if (m[i] == m[i+1]) {
			r++;
			continue;
		}
		ans += r*(r-1)/2;
		r = 1;
		printf("Yay #: %lld\n", i);
	}
	ans += r*(r-1)/2;

	printf("%lld\n", ans);
}

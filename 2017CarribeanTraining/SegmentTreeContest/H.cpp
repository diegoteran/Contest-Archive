#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

#define MAXM 200100
#define uB 300010
const int MAXN = 300500;
const int MAXT = 4*MAXN;
#define fst first
#define snd second
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> rectangle; //((l,r),(b,t))

namespace demian {

struct node {
	int pnd;
	pii mx;
};

node st[MAXT];

void build(int n, int l, int r) {
	if (l == r) {
		st[n].mx = mp(0, l);
	}
	else {
		build(2*n, l, (l+r)/2);
		build(2*n+1, (l+r)/2 + 1, r);
		st[n].mx = max(st[2*n].mx, st[2*n+1].mx);
	}
}

void push(int n) {
	if (st[n].pnd == 0)
		return;
	if (2*n < MAXT) st[2*n].pnd += st[n].pnd;
	if (2*n+1 < MAXT) st[2*n+1].pnd += st[n].pnd;
	st[n].mx.fst += st[n].pnd;
	st[n].pnd = 0;
}

void update(int x, int y, int z, int n, int l, int r) {
	push(n);
	if (r < x || l > y) {
		return;
	}
	if (x <= l && r <= y) {
		// printf("Deje un %d pendiente en el rango [%d, %d]\n", z, l, r);
		st[n].pnd += z;
		push(n);
		// printf("El rango [%d, %d] ahora tiene como maximo %d\n", l, r, st[n].mx.fst);
		return;
	}
	update(x, y, z, 2*n, l, (l+r)/2);
	update(x, y, z, 2*n+1, (l+r)/2 + 1, r);
	st[n].mx = max(st[2*n].mx, st[2*n+1].mx);
	
	// printf("Actualice el rango [%d, %d] a %d\n", l, r, st[n].mx.fst);
}

pii query(int x, int y, int n, int l, int r) {
	push(n);
	if (r < x || l > y) {
		return mp(-1, -1);
	}
	if (x <= l && r <= y) {
		// printf("el maximo en el rango [%d %d] es %d\n", l, r, st[n].mx.fst);
		return st[n].mx;
	}

	return max(query(x, y, 2*n, l, (l+r)/2), query(x, y, 2*n+1, (l+r)/2 + 1, r));
}

pair<int, pii> pointInmaxRectInt(vector<pair<pii, pii> > &rs) {
	vector<pair<pii, pii> > ev;
	for (int i = 0; i < rs.size(); i++) {
		ev.push_back(mp(mp(rs[i].fst.fst, 1), mp(rs[i].snd.fst, rs[i].snd.snd - 1)));
		ev.push_back(mp(mp(rs[i].fst.snd, -1), mp(rs[i].snd.fst, rs[i].snd.snd - 1)));
	}

	build(1, 0, MAXN - 1);
	pair<int, pii> ans;
	pii cand;
	sort(ev.begin(), ev.end());
	for (int i = 0; i < ev.size(); i++) {
		// printf("Actualiza el rango [%d %d] con %d\n", ev[i].snd.fst, ev[i].snd.snd, ev[i].fst.snd);
		update(ev[i].snd.fst, ev[i].snd.snd, ev[i].fst.snd, 1, 0, MAXN-1);
		cand = query(0, MAXN - 1, 1, 0, MAXN-1);
		ans = (cand.fst > ans.fst) ? mp(cand.fst, mp(ev[i].fst.fst, cand.snd)) : ans;
		//ans = max(ans, mp(cand.fst, mp(ev[i].fst.fst, cand.snd)));
		// printf("La maxima interseccion hasta este momento se da en da en (%d, %d) con %d intersecciones\n", ans.snd.fst, ans.snd.snd, ans.fst);
	}
	return ans;
}

}


int n, d, dir[MAXM], x, y;
char c;
pii p[MAXM];
map<int, int> m, mi;
vector<rectangle> r;


int main(){

	scanf("%d", &n);
	p[0] = mp(0, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d %c", &d, &c);
		if (dir[i] == 0) y+=d;
		if (dir[i] == 1) x+=d;
		if (dir[i] == 2) y-=d;
		if (dir[i] == 3) x-=d;
		p[i+1] = mp(x, y);
		m[x] = m[y] = 0;
		dir[i+1] = (dir[i] + (c == 'R' ? 1: -1))%4;
		if (dir[i+1] < 0) dir[i+1]+=4;		
	}

	int last = 1;
	for (map<int, int>::iterator t= m.begin(); t!=m.end(); t++)
		t->second = last++;
	
	for (map<int, int>::iterator t= m.begin(); t!=m.end(); t++)
		mi[t->second] = t->first;
	
	for (int i = 0; i <= n; i++)
		p[i] = mp(m[p[i].first] , m[p[i].second]);

	for (int i = 0; i < n; i++) {
		
		if (dir[i] == 0) { 
			r.push_back(mp(mp(p[i].first, uB), mp(p[i].second, p[i+1].second)));
			if (dir[i+1] == 1)
				r.push_back(mp(mp(p[i].first, uB), mp(0, p[i+1].second)));
			else
				r.push_back(mp(mp(p[i].first, uB), mp(p[i+1].second, uB)));
		}
		if (dir[i] == 1) { 
			r.push_back(mp(mp(p[i].first, p[i+1].first), mp(0, p[i+1].second)));
			if (dir[i+1] == 2)
				r.push_back(mp(mp(0, p[i+1].first), mp(0, p[i+1].second)));
			else
				r.push_back(mp(mp(p[i+1].first, uB), mp(0, p[i+1].second)));
		}
		if (dir[i] == 2) { 
			r.push_back(mp(mp(0, p[i].first), mp(p[i+1].second, p[i].second)));
			if (dir[i+1] == 3)
				r.push_back(mp(mp(0, p[i].first), mp(p[i+1].second, uB)));
			else
				r.push_back(mp(mp(0, p[i].first), mp(0, p[i+1].second)));
		}
		if (dir[i] == 3) { 
			r.push_back(mp(mp(p[i+1].first, p[i].first), mp(p[i].second, uB)));
			if (dir[i+1] == 0)
				r.push_back(mp(mp(p[i+1].first, uB), mp(p[i+1].second, uB)));
			else
				r.push_back(mp(mp(0, p[i+1].first), mp(p[i+1].second, uB)));
		}
	}
//
//	for (int i = 0; i < r.size(); i++) {
//		printf("%d %d %d %d\n", r[i].fst.fst, r[i].fst.snd, r[i].snd.fst, r[i].snd.snd);
//	}

	pair<int, pii> ansP = demian::pointInmaxRectInt(r);
	pii ans = ansP.second;

	printf("Ans C: %d %d  Int: %d\n", ans.fst, ans.snd, ansP.fst);
	
	if (ans.first >= 1 && ans.first < last) 
		ans.first = mi[ans.first];
	else if (ans.first == 0)
		ans.first = -1000000000;
	else
		ans.first = 1000000000;


	if (ans.second >= 1 && ans.second < last) 
		ans.second = mi[ans.second];
	else if (ans.second == 0)
		ans.second = -1000000000;
	else
		ans.second = 1000000000;

	printf("%d %d\n", ans.first, ans.second);
}

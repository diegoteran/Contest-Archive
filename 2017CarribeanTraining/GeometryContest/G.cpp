#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

#define EPS 1e-7
#define epsilon 0
#define MAXN 1000100
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

struct PT{

	double x, y;
	PT() {}
	PT(double x, double y): x(x), y(y) {}
	PT operator + (const PT &p) const {return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) const {return PT(x - p.x, y - p.y); }
	PT operator * (double c) const {return PT(x*c, y*c); }
	PT operator / (double c) const {return PT(x/c, y/c); }

};

double dot(PT p, PT q){
	return p.x*q.x + p.y*q.y;
}

double dist2(PT p, PT q){
	return dot(p-q,p-q);
}

double cross(PT p, PT q){
	return p.x*q.y - p.y*q.x;
}

bool linesParallel(PT a, PT b, PT c, PT d){
	return fabs(cross(b-a, c-d)) < EPS;
}

bool linesCollinear(PT a, PT b, PT c, PT d){
	return linesParallel(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS;
}

PT linesIntersection(PT a, PT b, PT c, PT d){
	b = b - a;
	d = c - d;
	c = c - a;
	return a + b*cross(c, d)/cross(b, d);
}


vector<PT> polygon;
vector<pii> lines;
double a, b, lI, rI;
PT ans, temp, p1, p2;
ll N;

pair<PT, PT> move(PT curr, PT nxt){
	if (nxt.y > curr.y) {
			nxt.x += EPS;
			curr.x += EPS;
		} else if (nxt.y < curr.y) {
			nxt.x -= EPS;
			curr.x -= EPS;
		} else {
			if (nxt.x < curr.x) {
				nxt.y += EPS;
				curr.y += EPS;
			} else {
				nxt.y -= EPS;
				curr.y -= EPS;
			}
		}
	return mp(curr, nxt);
}


bool testAttack(ll skip) {
	ans = PT(MAXN, MAXN);
	PT curr, nxt;
	lines.clear();
	for (ll i = 0; i < N; i++)
		lines.push_back(mp(i,(i+skip+1)%N));
	random_shuffle(lines.begin(), lines.end());
	for (ll i = 0; i < N; i++) {
		curr = polygon[lines[i].first];
		nxt = polygon[lines[i].second];
		
			
		if (cross(nxt-curr, ans-curr) <= EPS) continue; //Yaay \o/
		lI = -MAXN;
		rI = MAXN;			
		for (ll j = 0; j < i; j++) {
			p1 = polygon[lines[j].first];
			p2 = polygon[lines[j].second];
			pair<PT, PT> pp = move(p1, p2);
			p1 = pp.first;
			p2 = pp.second;
			if (linesParallel(nxt, curr, p1, p2)) continue;
			temp = linesIntersection(nxt, curr, p1, p2);
			if (linesParallel(nxt, curr, PT(0, 0), PT(0, 1))) {
				double c = cross(p2 - p1, linesIntersection(nxt, curr, PT(0,lI), PT(1, lI)) - p1);	
				if (temp.y < lI && c >= -EPS)
					return false;
				if (temp.y > rI && c >= -EPS)
					return false;
				if (c >= -EPS)
					lI = max (lI, temp.y + epsilon);
				else
					rI = min (rI, temp.y - epsilon);
				if (rI <= lI + EPS)
					return false;

				continue;
			}
			double c = cross(p2 - p1, linesIntersection(nxt, curr,  PT(lI, 0), PT(lI, 1)) - p1);
			if (temp.x < lI && c >= -EPS)
				return false;
			if (temp.x > rI && c >= -EPS)
				return false;
			if (c >= -EPS)
				lI = max (lI, temp.x + epsilon);
			else
				rI = min (rI, temp.x - epsilon);
			if (rI <= lI + EPS) 
				return false;
		}
		if (linesParallel(nxt, curr, PT(0, 0), PT(0, 1)))
			ans = PT(nxt.x, rI);
		else {
			p1 = linesIntersection(nxt, curr, PT(lI, 0), PT(lI, 1));
			p2 = linesIntersection(nxt, curr, PT(rI, 0), PT(rI, 1));
			ans = (p1.y > p2.y ? p1 : p2);
		}

	}
	return true;

}

int main() {

	scanf("%lld", &N);

	if (N <= 3) {
		printf("1\n");
		return 0;
	}
	
	for (ll i = 0; i < N; i++){
		scanf("%lf %lf", &a, &b); //Given in Clockwise direction
		polygon.push_back(PT(a, b));
	}

	ll low = 1, hi = N - 2, mid;
	while (low < hi) {
		mid = (low + hi)/2;
		if (testAttack(mid))
			low = mid + 1;
		else
			hi = mid;
	}

	printf("%lld\n", hi);

}






#include <bits/stdc++.h>

#define EPS 1e-14

using namespace std;

typedef long double ld;

struct PT{

	ld x, y;
	PT() {}
	PT(ld x, ld y): x(x), y(y) {}
	PT operator + (const PT &p) const { return PT(x + p.x, y + p.y);}
	PT operator - (const PT &p) const { return PT(x - p.x, y - p.y);}
	PT operator * (double c) const { return PT(x * c, y * c);}
	PT operator / (double c) const { return PT(x / c, y / c);}
	bool operator < (const PT &p) const { return (x < p.x || (x == p.x && y < p.y));}

};

ld dot(PT p, PT q) { return p.x*q.x + p.y*q.y; }
ld dist2(PT p, PT q) { return dot(p-q, p-q); }
ld dist(PT p, PT q) { return sqrt((ld)dist2(p, q)); }
ld cross(PT p, PT q) { return p.x*q.y - p.y*q.x; }

PT linesIntersection(PT a, PT b, PT c, PT d){
	b = b - a;
	d = c - d;
	c = c - a;
	return a + b*cross(c, d)/cross(b, d);
}

bool linesParallel(PT a, PT b, PT c, PT d){
	return fabs(cross(b-a, c-d)) < EPS;
}

bool linesCollinear(PT a, PT b, PT c, PT d){
	return linesParallel(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS; 
}

bool belongs(PT a, PT b, PT c){
	return dist(a, c) + dist(c, b) <= dist(a, b) + EPS;
}

int N, M;
vector<PT> polygon, points;
PT a, b, c, aux;
ld x, y, w, z, ans;
bool flag;

void calculateIntersections(){
	points.clear();
	flag = false;
	for (int i = 0; i < N; i++){
		if (linesCollinear(polygon[i], polygon[(i+1)%N], a, b)){
			ans += dist(polygon[i], polygon[(i+1)%N]);
			continue;
		}
		cout << "here 1" << endl;
		if (linesParallel(polygon[i], polygon[(i+1)%N], a, b))
			continue;
		cout << "here 2" << endl; 
		aux = linesIntersection(polygon[i], polygon[(i+1)%N], a, b);
		cout << "aux " << aux.x << " " << aux.y << endl;
		if (!belongs(polygon[i], polygon[(i+1)%N], aux)) continue;
		cout << "here 3" << endl;
		if (dist(aux, polygon[i]) < EPS) continue;
		cout << "here 4" << endl;
		if (dist(aux, polygon[(i+1)%N]) > EPS){
			points.push_back(aux);
			continue;
		}
		cout << "here 5" << endl;
		c = (a + b)/2;
		if (cross(c - aux, polygon[i] - aux)*cross(c - aux, polygon[(i+2)%N] - aux) <= EPS)
			points.push_back(aux);
	}
}

int main(){

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> x >> y;
		polygon.push_back(PT(x, y));
	}

	while (M--){
		
		cin >> x >> y >> w >> z;
		a = PT(x, y); b = PT(w, z);
		ans = 0;
		calculateIntersections();
		sort(points.begin(), points.end());
		for (int i = 0; i < points.size(); i += 2){
			ans += dist(points[i], points[i+1]); 
			cout << points[i].x << " " << points[i].y << endl;
		}
		cout << setprecision(12) << ans << endl;
	}
}

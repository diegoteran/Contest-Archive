#include <cstdio>
#include <cmath>
#include <algorithm>

#define EPS 1e-12

using namespace std;

struct PT{

	double x, y;
	PT() {}
	PT(double x, double y): x(x), y(y) {}
	PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
	PT operator * (double c) const { return PT(x*c, y*c); }
	PT operator / (double c) const { return PT(x/c, y/c); }
	bool operator < (const PT &p) const { return x < p.x; } //Problem specific

};

double dot(PT p, PT q){ return p.x*q.x + p.y*q.y; }
double dist2(PT p, PT q){ return dot(p-q, p-q); }
double dist(PT p, PT q){ return sqrtf(dist2(p,q)); }
double cross(PT p, PT q){ return p.x*q.y - p.y*q.x; }

PT linesIntersection(PT a, PT b, PT c, PT d){
	b = b - a;
	d = c - d;
	c = c - a;
	return a + b*cross(c, d)/cross(b, d);
}

double ans;
int T, N, i, j, x, y, firstH[105];
PT p[105], a, b;

int main(){

	scanf("%d", &T); 
	while(T--){
		scanf("%d", &N);
		p[0] = PT(0, 10000); firstH[0] = 0; //Problem specific
		for(i = 1; i <= N; i++){
			scanf("%d %d", &x, &y);
			p[i] = PT(x, y);
		}
		sort(p+1, p+N+1);

		//All nearest larger values
		for(i = 1; i <= N; i++){
			j = i-1;
			while(p[j].y <= p[i].y)
				j = firstH[j];
			firstH[i] = j;	
		}
		
		ans = 0;
		if(N < 2)
			printf("0.00\n");
		else{
			i = N-1; b = p[N];
			while(i){
				a = p[i];
				ans += dist(a, b);
				i = firstH[i];
				b = linesIntersection(p[i], p[i+1], a, PT(0, a.y));
			}

			printf("%.2lf\n", ans);

		}

	}
}

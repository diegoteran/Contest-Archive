#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

#define PI 3.14159265358979323846
using namespace std;

double INF = 1e100;
double EPS = 1e-12;

struct PT { 
	  double x, y; 
	    PT() {}
	      PT(double x, double y) : x(x), y(y) {}
	        PT(const PT &p) : x(p.x), y(p.y)    {}
		  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
		    PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
		      PT operator * (double c)     const { return PT(x*c,   y*c  ); }
		        PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
	  os << "(" << p.x << "," << p.y << ")"; 
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
	  double r = dot(b-a,b-a);
	    if (fabs(r) < EPS) return a;
	      r = dot(c-a, b-a)/r;
	        if (r < 0) return a;
		  if (r > 1) return b;
		    return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c) {
	  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

PT  points[100010], P;
int N, i;
double mini, maxi, temp;

int main(){
	maxi = 0;
	mini = 1000000000000000000;
	scanf("%d", &N);
	cin >> P.x >> P.y;
	for(i = 0; i < N; i++){
		cin >> points[i].x >> points[i].y;
		if(mini >  sqrt((points[i].x-P.x)*(points[i].x-P.x) + (points[i].y-P.y)*(points[i].y-P.y)))
			mini = sqrt((points[i].x-P.x)*(points[i].x-P.x) + (points[i].y-P.y)*(points[i].y-P.y));
	}
	for(i = 0; i < N; i++){
		
		if(mini > DistancePointSegment(points[i], points[(i+1)%N], P))
			mini = DistancePointSegment(points[i], points[(i+1)%N], P); 
		if(maxi < dist2(points[i], P))
			maxi = dist2(points[i],P);
	}

	printf("%.9lf\n", PI*(maxi-mini*mini));

}

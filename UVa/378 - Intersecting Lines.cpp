#include <cstdio>
#include <cmath>

#define EPS 1e-12

using namespace std;

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

int N, i;
double a, b, c, d;
PT p1, p2, q1, q2, r;

int main(){

	scanf("%d", &N);
	printf("INTERSECTING LINES OUTPUT\n");
	for(i = 0; i < N; i++){

		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		p1 = PT(a, b);
		p2 = PT(c, d);
		
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		q1 = PT(a, b);
		q2 = PT(c, d);

		if(linesCollinear(p1, p2, q1, q2))
			printf("LINE\n");
		else if(linesParallel(p1, p2, q1, q2))
			printf("NONE\n");
		else{
			r = linesIntersection(p1, p2, q1, q2);
			printf("POINT %.2lf %.2lf\n", r.x, r.y); 
		}

	}
	printf("END OF OUTPUT\n");
}


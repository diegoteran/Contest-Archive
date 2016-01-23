#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

#define EPS 1e-12

using namespace std;

struct PT{

	int x, y;
	PT() {}
	PT(int x, int y): x(x), y(y) {}
	PT operator + (const PT &p) const {return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) const {return PT(x - p.x, y - p.y); }
	PT operator * (double c) const {return PT(x*c, y*c); }
	PT operator / (double c) const {return PT(x/c, y/c); }

};

long long dot(PT p, PT q){
		return p.x*q.x + p.y*q.y;
}

long long dist2(PT p, PT q){
		return dot(p-q,p-q);
}

PT f1, f2, p[2005];
int N, i, j;
long long r1, r2, mini;

int main(){
	mini = 100000000000000000;
	scanf("%d %d %d %d %d", &N, &f1.x, &f1.y, &f2.x, &f2.y);
	for(i = 0; i < N; i++)
		scanf("%d %d", &p[i].x, &p[i].y);

		
	for(i = 0; i < N; i++){
		r1 = dist2(f1, p[i]);
		r2 = 0;
		
		for(j = 0; j < N; j++)
			if(dist2(f1, p[j]) > r1)
				r2 = max(r2, dist2(f2, p[j])); 

		mini = min(mini, r1+r2);
	}

	cout << mini << endl;

}






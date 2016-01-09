#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

double a, b, c, s, r, R, A, A2;

int main(){

	while( scanf("%lf %lf %lf", &a, &b, &c) != EOF){
		s = (a + b + c)/2; //Semiperimeter
		A2 = (a+b+c)*(b+c-a)*(a+c-b)*(a+b-c)/16;
		A = 0.25*sqrtf( (a+(b+c)) * (c-(a-b)) * (c+(a-b)) * (a+(b-c))); //Heron's Formula
		r = 1/s;
		R = a*b*c/4;
		
		printf("%.4lf %.4lf %.4lf\n", (R*R/A2*atan(1)*4-A), (A-r*r*A2*atan(1)*4), (r*r*A2*atan(1)*4)); 
	}
}

#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std; 
#define PI 3.14159265
int T, p, x, y, a2, b2, c2;
double a, b, c, ang;

int main(){

	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d %d", &p, &x, &y);
		a2 = 50*50;
		b2 = (x-50)*(x-50) + (y-100)*(y-100);
		c2 = (x-50)*(x-50) + (y-50)*(y-50);
		a = 50;
		b = sqrt((double)b2);
		c = sqrt((double)c2);
		if (c == 0) 
			ang = 0;
		else
			ang = acos(-(b2-c2-a2)/(2*c*a))*180/PI;
		if (50 > x ) ang = 360 - ang;
//		printf("%f %f %f %f \n", ang, 3.6*p ,b ,c);
		if (p == 0 || 360*p/100 < ang || c2 > 50*50)
			printf("Case #%d: white\n", i);
		else
			printf("Case #%d: black\n", i);
		
	}

}

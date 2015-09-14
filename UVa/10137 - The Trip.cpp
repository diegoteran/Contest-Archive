#include <cstdio>
#include <cmath>

using namespace std;

int n;
double a[1010], avg;
double dif1, dif2;

int main() {
	int i;
	double temp;
	while (scanf("%d", &n), n){
		
		avg = 0;
		for (i = 0; i < n; i++){
			scanf("%lf", &temp);
			a[i] = temp;
			avg += temp;
		}
		avg = round(avg*100/n)/100;
		
		dif1 = dif2 = 0;
		for (i = 0; i < n; i++)
			if(avg >= a[i])
				dif1 += avg - a[i];
			else
				dif2 += a[i] - avg;
		
		
		printf("$%.2lf\n", dif1 < dif2 ? dif1: dif2);
	}
}
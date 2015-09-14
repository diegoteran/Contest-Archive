#include <iostream>
using namespace std;

long long cant[1000010];
long long T;

int main() {
	cant[4] = 1;
	
	long long i;
	
	for(i=5; i<1000001; i++)
		if(i%2==0)
		 	cant[i] = cant[i-1] + ((i-2)/2)*((i-2)/2);
		else
			cant[i] = cant[i-1] + ((i-3)/2)*((i-3)/2 +1);
	
	
	while(scanf("%lld", &T), T>2){
		printf("%lld\n", cant[T]);
	}
	return 0;
}
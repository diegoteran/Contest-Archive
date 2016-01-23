#include <cstdio>

using namespace std;
int main(){
	int a, b, i, n;
	a = 1;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &b);
		a *= b;
	}

	printf("%d\n", a);

}

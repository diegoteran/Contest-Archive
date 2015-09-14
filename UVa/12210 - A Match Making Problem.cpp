#include <cstdio>
#include <algorithm>
using namespace std;

int B, S, bach[10010];

int main() {
	int i, j=0, null;
	while (scanf("%d %d", &B, &S), j++, B+S){
		for (i = 0; i < B; i++)
			scanf("%d", &bach[i]);
		for (i = 0; i < S; i++)
			scanf("%d", &null);
		sort(bach, bach + B);
		B <= S ? printf("Case %d: 0\n", j) : printf("Case %d: %d %d\n", j, B-S, bach[0]);
	}
}
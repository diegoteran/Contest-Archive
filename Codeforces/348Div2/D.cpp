#include <cstdio>

using namespace std;

#define MAXN 1000010

int N, q, t, x, ar[MAXN];

int main(){

	int pos1, pos2;
	pos1 = 0;
	pos2 = 1;
	
	scanf("%d %d", &N, &q);
	while (q--){

		scanf("%d", &t);
		if (t == 2){
			pos1 ^= 1;
			pos2 ^= 1;
			continue;
		}

		scanf("%d", &x);
		if (x < 0)
			x += N;
		
		pos1 = (pos1 + x)%N;
		pos2 = (pos2 + x)%N;
	}

	ar[pos1] = 1;
	ar[pos2] = 2;

	for (int i = (pos1 + 2)%N, j = 3; i != pos1; i = (i + 2)%N, j += 2)
		ar[i] = j;

	for (int i = (pos2 + 2)%N, j = 4; i != pos2; i = (i + 2)%N, j += 2)
		ar[i] = j;
	
	for (int i = 0; i < N-1; i++){
		printf("%d ", ar[i]);
	}
	printf("%d\n", ar[N-1]);
}

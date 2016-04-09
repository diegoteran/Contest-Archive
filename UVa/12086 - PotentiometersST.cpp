#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXN 200010
#define left 2*node
#define right 2*node+1
#define mid ((lo+hi)/2)

using namespace std;

int N, x, y, a[MAXN], segTree[4*MAXN], t;
char c[5];

//Segment Tree
void build(int lo, int hi, int node){
	if (lo == hi){
		segTree[node] = a[hi];
		return;
	}
	build(lo, mid, left);
	build(mid+1, hi, right);
	segTree[node] = segTree[left] + segTree[right];
}

int query(int qlo, int qhi, int lo, int hi, int node){
	if (qlo <= lo && hi <= qhi)
		return segTree[node];
	if (qhi < lo || hi < qlo)
		return 0;
	return query(qlo, qhi, lo, mid, left) + query(qlo, qhi, mid+1, hi, right);

}

void update(int pos, int r, int lo, int hi, int node){

	if (pos < lo || pos > hi) return;
	if (lo == hi){
		segTree[node] = r;
		return;
	}
	update (pos, r, lo, mid, left);
	update (pos, r, mid+1, hi, right);
	segTree[node] = segTree[left] + segTree[right];

}

int main(){

	while (t++, scanf("%d", &N), N){
		
		if(t > 1)
			printf("\n");
		fill(segTree, segTree+4*MAXN, 0);	
		printf("Case %d:\n", t);
		for (int i = 1; i <= N; i++)
			scanf("%d", &a[i]);
		build(1, N, 1);		

		while (scanf("%s", c), c[0] != 'E'){
			scanf("%d %d", &x, &y);
			if (c[0] == 'S')
				update(x, y, 1, N, 1);	
			else
				printf("%d\n", query(x, y, 1, N, 1));
		}

	}

}

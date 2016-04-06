#include <cstdio>
#include <algorithm>

#define MAXN 100010
#define left (2*node+1)
#define right (2*node+2)
#define mid ((lo+hi)/2)
using namespace std;

int ar[MAXN], segTree[4*MAXN], fr[MAXN], N, Q, x, y;

//Segment Tree
void build(int lo, int hi, int node){
	if (lo == hi){
		segTree[node] = fr[lo];
		return;
	}
	build(lo, mid, left);
	build(mid+1, hi, right);
	segTree[node] = max(segTree[left], segTree[right]);
}

int query(int qlo, int qhi, int lo, int hi, int node){
	if (qlo <= lo && hi <= qhi) //total overlap
		return segTree[node];
	if (qhi < lo || hi < qlo) //no overlap
		return -1;
	return max(query(qlo, qhi, lo, mid, left), query(qlo, qhi, mid+1, hi, right));	
}

//Calculate frequencies
void frequencies(){

	for (int i = 0, j; i < N; i = j){
		for (j = i+1; j < N && ar[i] == ar[j]; j++);
		
		for (int k = i; k < j; k++)
			fr[k] = j - i;
	}

}

//binary search for modified range
int lastToRight(int x){
	int l = 0, h = N, m; 
	while (l != h){
		m = (l+h)/2;
		if (ar[m] <= x)
			l = m+1;
		else
			h = m;
	}
	return h-1;
}

int firstToLeft(int x){
	int l = 0, h = N, m;
	while (l != h){
		m = (l+h)/2;
		if (ar[m] >= x)
			h = m;
		else
			l = m+1;
	}
	return h;
}

int main(){

	while (scanf("%d %d", &N, &Q) == 2){

		for (int i = 0; i < N; i++)
			scanf("%d", ar + i);

		frequencies();
		build(0, N-1, 0);

		for (int i = 0; i < Q; i++){
			scanf("%d %d", &x, &y); x--; y--;
			int l = lastToRight(ar[x]); l++;
			int r = firstToLeft(ar[y]); r--;
			int ans = max(min(l-x, y-x+1), min(y-r, y-x+1));
			if (l <= r)
				ans = max(ans, query(l, r, 0, N-1, 0));
			printf("%d\n", ans);
		}

	}

}

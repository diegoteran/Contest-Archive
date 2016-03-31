#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100005

int N, x;
int tree[MAXN];

void update(int c, int idx){

	for(; idx <= MAXN; idx += (idx&-idx))
		tree[idx] += c;

}

int query(int idx){
	
	int ans = 0;
	for(; idx; idx -= (idx&-idx))
		ans += tree[idx];
	
	return ans;
}

int main(){

	scanf("%d", &N);
	long long ans = 0;
	for(int i = 0; i < N; i++){

		scanf("%d", &x);
		if(x != 1)
			ans += x - query(x) - 1;

		update(1, x); 

	}

	printf("%lld\n", ans);

}

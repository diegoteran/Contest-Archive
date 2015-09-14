#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(const pair<short, short> &a, const pair<short, short> &b){
	return a.first*b.second < b.first*a.second ;
}

pair<short, short> frac[500600];

int N,P;

int main() {
	short i,j; 
	long long count;
	while(scanf("%d %d", &N, &P) == 2){
		
		count=0;
		
		for(i=1; i<=N; i++)
			for(j=1; j<=i; j++)
				if(__gcd(i,j)==1)
					frac[count++] = make_pair (j, i);
	
		sort(frac, frac+count, cmp);
		
		printf("%hd/%hd\n", frac[P-1].first, frac[P-1].second);
	}
}
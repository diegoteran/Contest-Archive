#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

/*Min-heap, sacar 2, sumar y devolver */

int n;
priority_queue<int, vector<int>, greater<int>> p;
long long ans;

int main() {
	
	int i, temp1, temp2;
	while (scanf("%d", &n), n){
		
		for (i = 0; i < n; i++){
			scanf("%d", &temp1);
			p.push(temp1);
		}	
		
		ans = 0;
		while(p.size() > 1){
			temp1 = p.top();
			p.pop();
			temp2 = p.top();
			p.pop();
			ans += temp1 + temp2;
			p.push(temp1 + temp2);
		}
		p.pop();
			
		printf("%lld\n", ans);
	}
	
}
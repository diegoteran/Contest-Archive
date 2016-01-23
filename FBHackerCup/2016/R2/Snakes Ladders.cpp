//WRONG ANSWER

#include <cstdio>
#include <algorithm>
#include <stack>

#define MOD 1000000007

using namespace std;

struct lad{
	long long x, y;
	bool operator < (const lad &p) const { return x < p.x; } //Problem specific
};

stack<lad> s1, s2;
lad l[20100], dis[20100];
long long t, T, N, i, j, ans;
long long cont;

int main(){

	scanf("%lld", &T);
	while(t++, T--){

		scanf("%lld", &N);
		for(i = 0; i < N; i++)
			scanf("%lld %lld", &l[i].x, &l[i].y);

		sort(l, l+N);
		ans = 0;
		s1.push(l[0]);
		for(i = 1; i < N; i++){
		
			while(!s1.empty() && l[i].y > s1.top().y){
				s2.push(s1.top());
				s1.pop();
			}
			
			while(!s2.empty()){
				if(cont){
					if(s2.top().y == dis[cont-1].y){
						for(j=cont-1; j >=0; j--)
							ans =  (ans + (s2.top().x - dis[j].x)*(s2.top().x - dis[j].x))%MOD;
							
						dis[cont++] = s2.top();
						s2.pop();
					}else{
						cont = 0;
					}					
				} else{

					dis[cont++] = s2.top();
					s2.pop();

				}		

			}

			s1.push(l[i]);

		}

		printf("Case #%lld: %lld\n", t, ans);
		
	}

}

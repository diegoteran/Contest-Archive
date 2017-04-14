#include <cstdio>
#include <algorithm>

using namespace std;

int T, N, w[200], cnt, ans;

int main(){
	
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
	
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			scanf("%d", w + j);
		
		ans = 0;
		sort(w, w+N);
		for (int j = 0; j < N; j++) {
			cnt = 0;
			for (int k = j; k < N; k++){
				cnt += 50/w[k];
				if(w[k] <= 50 && 50%w[k] == 0)
					cnt--;
			} 
			if (cnt <= j)
				ans = max(ans, N - j);
		}
	
		printf("Case #%d: %d\n", i, ans);	
	}

}

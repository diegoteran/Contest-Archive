#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N, s1[10100], s2[10100], i, j, t, T, changes[10100], fd[10100], ans;
string str1, str2;

int main(){

	scanf("%d", &T);
	while(t++, T--){

		scanf("%d", &N);
		cin >> str1 >> str2;
		for(i = 0; i < N; i++){
			s1[i] = str1[i] - 'A';
			s2[i] = str2[i] - 'A';
		}
		str1[N] = 0;
		str2[N] = 1;

		for(i = 0, j = 0; i < N; i++){
			if(j < i)
				j = i;
			while(str1[j] == str2[j])
				j++;
			fd[i] = j;
		}

		changes[N-1] = 1;
		for(i = N-2; i >= 0; i--){
			changes[i] = changes[i+1];
			if(str2[i] != str2[i+1])
				changes[i]++;
		}
		changes[N] = 0;

		ans = changes[fd[0]];
		for(i = 1; i < N; i++)
			ans = min(ans, max(changes[fd[i]], changes[0] - changes[i-1]+1));

		printf("Case #%d: %d\n", t, ans);

	}

}

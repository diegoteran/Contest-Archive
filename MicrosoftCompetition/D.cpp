#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

char word[100];
int counr[100], fact[100];
bool flag;

int main(){
	int i, j, n, x, s, z;
	
	fact[0] = 1;
	for(i = 1; i <= 10; i++){
		fact[i] = i *(fact[i-1]);
	}

	while(scanf("%s", word) != EOF){
		n = strlen(word);
		x = 0;
		s = 0;
		z = 0;
		for(i = 0; i < 28; i++)
			counr[i] = 0;
		for(i = 0; i < n; i++){
			counr[(word[i] - 'a')]++;
		//	printf("con: %d\n", counr[(word[i] - 'a')]);
		}

		if((n % 2) == 0){
			flag = false;
			for(i = 0; i < (('z' - 'a') + 1); i++){
				if((counr[i] % 2) == 1 && flag){
					x++;
					counr[i] = counr[i]/2;
					z += counr[i];
				
				}
				else if((counr[i] % 2) == 1){
					counr[i] = counr[i]/2;
					z += counr[i];
					flag = true;
				}
				else{
					counr[i] = counr[i]/2;
					z += counr[i];
				}
			}
			s = fact[z];
			//printf("s: %d\n", s);
			//printf("x: %d\n", x);
			for(i = 0; i < (('z' - 'a') + 1); i++)
				s = s/fact[counr[i]];
			printf("%d,%d\n", x, s);
		}
		else{
			flag = false;
			for(i = 0; i < (('z' - 'a') + 1); i++)
				if((counr[i] % 2) == 1 && flag){
					x++;
					counr[i] = counr[i]/2;
					z += counr[i];
				
				}
				else if((counr[i] % 2) == 1){
					counr[i] = counr[i]/2;
					flag = true;
					z += counr[i];
				}
				else{
					counr[i] = counr[i]/2;
					z += counr[i];
				}
			s = fact[z];
			for(i = 0; i < (('z' - 'a') + 1); i++)
				s = s/fact[counr[i]];
			printf("%d,%d\n", x, s);
		}
	}
}

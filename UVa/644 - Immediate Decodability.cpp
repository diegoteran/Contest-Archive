#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

string str, st[10];
int cont, i, j, t;

int main(){
	cont = 0;
	t = 0;
	while (getline(cin, str), !str.empty()){
		
		
		if (str[0] != '9'){
			st[cont++] = str;
			continue;
		}
		
		sort(st, st +cont);

		for (i = 0; i < cont-1; i++){
			
			if (st[i].size() <= st[i+1].size()){
				for(j = 0; j < st[i].size(); j++)
					if(st[i][j] != st[i+1][j])
						break;
				if(j == st[i].size()){
					printf("Set %d is not immediately decodable\n", ++t);
					break;
				}
			}
		}
		if (i == cont-1)
			printf("Set %d is immediately decodable\n", ++t);

		cont = 0;
	}
}

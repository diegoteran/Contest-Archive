#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string si, sout;
int i, j, S, cf;
bool flag;

int main(){
	while (getline(cin, si), !si.empty() ){
		
		flag = false;
		sout = si;
		S = si.size();
		for (i = 0; i < S; i++){
			if(i == 0 && si[0] >= 'a' && si[0] <= 'z'){
				j = si[0] - 'a';
				sout[0] = 'A' + j;

				continue;
			}else

			if(!flag && si[i] >= 'A' && si[i] <= 'Z' && i > 0){
				j = si[i] - 'A';
				sout[i] = 'a' + j;

				continue;
			}else

			if(si[i] == '.' || si[i] == '?' || si[i] == '!'){
				cf = 1;
				flag = true;

				continue;
			}else

			if(flag && si[i] >= 'a' && si[i] <= 'z'){
				j = si[i] - 'a';
				sout[i] = 'A' + j;
				flag = false;

				continue;
			} else if(flag && si[i] >= 'A' && si[i] <= 'Z'){
				flag = false;
				continue;
			}
			
		}

		cout << sout << endl;

	}
}

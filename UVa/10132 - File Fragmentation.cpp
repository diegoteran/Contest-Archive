#include <iostream>
#include <map>
#include <string>

/*Checo todas las posibles parejas e imprimo la que más se repite. */

using namespace std;

int N;
string s;
map<string, int> m, m2;

int main() {
		int i, r, count;
 
		cin >> N;
		getline(cin, s); getline(cin, s);
		 
		for (i = 0; i < N; i++){
			m.clear();
			m2.clear();
		 	
		 	count = 0;
			while (!getline(cin, s).fail() && s != ""){
				m[s]++;
				count++;
			}
			
			r=0; 
			for (map<string, int>::iterator it = m.begin(); it != m.end(); it++){
				r += it->first.size()*it->second;	
			}
			
			r = r*2/count ;
				
			for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
				for (map<string, int>::iterator it2 = m.begin(); it2 != m.end(); it2++)
					if(it->first.size() + it2->first.size() == r){
						m2[it->first + it2->first] += it->second*it2->second;
						m2[it2->first + it->first] += it->second*it2->second;
					}
				
			
			
			r = 0;
			for (map<string, int>::iterator it = m2.begin(); it != m2.end(); it++)
				if(r < it->second){
					r = it->second;
					s = it->first;
				}
				
			cout << s << endl;
				
			if (i < N-1)
				cout << endl;
				
		}
}
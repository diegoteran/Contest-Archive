#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int N, i, maxx, sum;
string a[5], b;
map<string, int> c;

int main() {
	
	while(cin >> N, N){
		maxx =1;
		c.clear();
		for(i=1; i<=N; i++){
			b = "";
			cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
			sort(a, a+5);
			b = a[0]+a[1]+a[2]+a[3]+a[4];
			c[b]++;
		}
		sum = 0;
		for(map<string, int>::iterator it=c.begin(); it!=c.end(); it++){
			if(it->second == maxx)
				sum +=maxx;
			if(it->second > maxx){
				maxx = it->second;
				sum = maxx;
			}
		}
		cout << sum << endl;
	}
}
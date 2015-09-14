#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int N;
map<string, int> m;
string lin;
double d;

int main() {
	int i, sum;
	
	cin >> N;
	getline(cin, lin); getline(cin, lin);
	
	for (i = 0; i < N; i++){
		m.clear();
		
		while (!getline(cin, lin).fail() && lin != "")
			m[lin]++;
		
		sum = 0;
		for (auto it = m.begin(); it != m.end(); it++)
			sum += it->second;
		
		for (auto it = m.begin(); it != m.end(); it++){
			cout << it->first;
			printf(" %.04f\n", (double)100 * it->second / sum);
		}
		
		if (i < N-1)
			cout << endl;
	}
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

string r1, r2, m1, m2;
char n1[100], n2[100], ch;
int i, j, k, S1, S2;

int main(){
	m1 = m2 = "";
	while( scanf("%c", &ch), ch != ':'){
		m1 += ch;
	}
	getline(cin, r1);
	while( scanf("%c", &ch), ch != ':'){
		m2 += ch;
	}
	getline(cin, r2);
	S1 = r1.size();
	S2 = r2.size();

	int dif = 0;
	for(i = 0; i < 100000; i++){
		if(r1[i%S1] == 'R' && r2[i%S2] == 'S')
			dif++;
		
		if(r1[i%S1] == 'P' && r2[i%S2] == 'R')
			dif++;

		if(r1[i%S1] == 'S' && r2[i%S2] == 'P')
			dif++;

		if(r1[i%S1] == 'S' && r2[i%S2] == 'R')
			dif--;

		if(r1[i%S1] == 'R' && r2[i%S2] == 'P')
			dif--;

		if(r1[i%S1] == 'P' && r2[i%S2] == 'S')
			dif--;

		if(dif >= 5 or dif <= -5)
			break;

	}
	cout << i+1 << endl;
	if(dif >= 5)
		cout << m1 << endl;
	else if (dif <= -1)
		cout << m2 << endl;
	else
		cout << ":DRAW:" << endl;


}

#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct node{
	int next[30];
};

node nodes[100005*40];
bool endd[100005*40];

int N, i, j;
string s, out;

int main(){
	
	scanf("%d", &N);
	int count = 0; int curr;
	bool ans = true;
	for (i = 0; i < N; i++){
		cin >> s;
		for (curr = 0, j = 0; j < s.size(); j++){
			
			if ((endd[nodes[curr].next[s[j]-'a']]==true ||(s.size()-1==j && nodes[curr].next[s[j]-'a']>0))&& ans){
				out = s;
				ans = false;
			}
			
			if (nodes[curr].next[s[j] - 'a'] == 0)
				nodes[curr].next[s[j] - 'a'] = ++count;
			
			if (j == s.size()-1)
				endd[nodes[curr].next[s[j] - 'a']] = true;
			
			curr = nodes[curr].next[s[j]-'a'];
		}
	}

	if (ans)
		printf("GOOD SET\n");
	else
		cout << "BAD SET" << endl << out << endl;

}

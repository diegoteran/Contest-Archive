#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int T, t;
string str, ans;
int main(){

	cin >> T;
	while (t++, T--){

		cin >> str;
		ans = str[0];
		for (int i = 1; i < str.size(); i++)
			if (str[i] < ans[0])
				ans = ans + str[i];
			else
				ans = str[i] + ans;

		cout << "Case #" << t << ": " << ans << endl;

	}
	

}

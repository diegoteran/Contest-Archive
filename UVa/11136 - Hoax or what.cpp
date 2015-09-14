#include <iostream>
#include <set>

using namespace std;

int N, B, i, j, bill;
multiset<int> bills;
long long sum;
multiset<int>::iterator it, it2;
multiset<int>::reverse_iterator rit;

int main() {
	
	while( cin >> N, N){
		
		bills.clear();
		sum = 0;
		for( i = 0; i < N; i++){
			cin >> B;
			for( j = 0; j < B; j++){
				cin >> bill;
				bills.insert(bill);
			}
			rit = bills.rbegin();
			it = bills.begin();
			sum += *rit - *it;
			it2 = bills.lower_bound(*rit);
			bills.erase(it2);
			bills.erase(it);
			
		}
		
		cout << sum << endl;
	}
	
}
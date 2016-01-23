#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long x1, x2, x3, y1, y2, y3;

int main(){
	int ans = 0;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	if((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3))
		ans = 1;
	else 
		if((x1 == x2 && ((y1 > y2 && (y3 >= y1 || y3 <= y2)) || (y2 > y1 && (y3 >= y2 || y3 <= y1))))
		|| (x1 == x3 && ((y1 > y3 && (y2 >= y1 || y2 <= y3)) || (y3 > y1 && (y2 >= y3 || y2 <= y1))))
		|| ((x3 == x2 && ((y3 > y2 && (y1 >= y3 || y1 <= y2)) || (y2 > y3 && (y1 >= y2 || y1 <= y3))))))
		ans = 2;
	else
		ans = 3;

	printf("%d\n", ans);
			

	


}

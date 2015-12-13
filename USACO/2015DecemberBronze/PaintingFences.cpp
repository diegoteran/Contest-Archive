#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

int a, b, c, d, x;

int main(){
	ifstream in ("paint.in");
	ofstream out ("paint.out");
	in >> a >> b >> c >> d;
	in.close();
	x = b - a;
	if (d > b){
		if(c >= b)
			x += d - c;
		else if (c < a)
			x = d - c;
		else
			x += d - b;
	} else if(d <= a)
		x += d - c;
	else if(c < a)
		x += a - c;

	out << x << endl;
}

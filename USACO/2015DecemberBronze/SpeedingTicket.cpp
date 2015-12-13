#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int road[101], bessie[101], N, M, i, j, a, b, c, d;

int main(){

	ifstream in ("speeding.in");
	ofstream out ("speeding.out");

	in >> N >> M;

	j = 1;
	c = 0;
	for (i = 0; i < N; i++){
		in >> a >> b;
		c += a;
		for(; j <= c; j++)
			road[j] = b;
	}
	
	j = 1; c = 0;
	for (i = 0; i < M; i++){
		in >> a >> b;
		c += a;
		for(; j <= c; j++)
			bessie[j] = b;
	}

	d = 0;
	for (i = 1; i <= 100; i++)
		d = max(d, bessie[i] - road[i]);

	out << d << endl;

}

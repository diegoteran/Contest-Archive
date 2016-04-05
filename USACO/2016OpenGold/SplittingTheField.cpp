#include <iostream>
#include <fstream>
#include <algorithm>

#define fst first
#define snd second
#define MAXN 50010
#define mp make_pair

using namespace std;

typedef pair<long long, long long> pii;

long long N, x, y, xMax[MAXN], xMin[MAXN], yMax[MAXN], yMin[MAXN], A, B, a, b;
pii xf[MAXN];

int main(){

	ifstream in ("split.in");
	ofstream out ("split.out");

	in >> N;
	a = b = 1000000009;
	A = B = 0;
	for (int i = 0; i < N; i++){
		in >> x >> y;
		xf[i] = mp(x, y);
		a = min(a, x); b = min(b, y);
		A = max(A, x); B = max(B, y);
	}

	sort(xf, xf+N);
	
	yMax[0] = yMin[0] = xf[0].snd;
	xMax[N-1] = xMin[N-1] = xf[N-1].snd;
	for(int i = 1; i < N; i++){
		yMax[i] = max(yMax[i-1], xf[i].snd);
		yMin[i] = min(yMin[i-1], xf[i].snd);
		xMax[N-1-i] = max(xMax[N-i], xf[N-1-i].snd);
		xMin[N-1-i] = min(xMin[N-i], xf[N-1-i].snd);
	}

	long long ans = (xf[N-1].fst - xf[0].fst) * (yMax[N-1] - yMin[N-1]);
	for(int i = 1; i < N; i++)
		ans = min(ans, (xf[i-1].fst - xf[0].fst)*(yMax[i-1] - yMin[i-1]) 
							+ (xf[N-1].fst - xf[i].fst)*(xMax[i] - xMin[i]));


	for(int i = 0; i < N; i++)
		xf[i] = mp(xf[i].snd, xf[i].fst);

	
	sort(xf, xf+N);
	
	yMax[0] = yMin[0] = xf[0].snd;
	xMax[N-1] = xMin[N-1] = xf[N-1].snd;
	for(int i = 1; i < N; i++){
		yMax[i] = max(yMax[i-1], xf[i].snd);
		yMin[i] = min(yMin[i-1], xf[i].snd);
		xMax[N-1-i] = max(xMax[N-i], xf[N-1-i].snd);
		xMin[N-1-i] = min(xMin[N-i], xf[N-1-i].snd);
	}

	for(int i = 1; i < N; i++)
		ans = min(ans, (xf[i-1].fst - xf[0].fst)*(yMax[i-1] - yMin[i-1]) 
							+ (xf[N-1].fst - xf[i].fst)*(xMax[i] - xMin[i]));

	ans = (A-a)*(B-b) - ans;
	out << ans << endl;
}

#include <iostream>
#include <fstream>
#include <algorithm>

#define fst first
#define snd second
#define MAXN 50010
#define mp make_pair

using namespace std;

typedef pair<long long, long long> pii;

long long N, x, y;
pii xf[MAXN], yf[MAXN], zf[MAXN];

int main(){

	ifstream in ("reduce.in");
	ofstream out ("reduce.out");

	in >> N;
	for (int i = 0; i < N; i++){
		in >> x >> y;
		xf[i] = mp(x, y);
	}

	sort(xf, xf+N);

	if (N < 5)
		out << "0" << endl;
	else{

		long long ans = 2500000002;
		//3 from x
		for (int i = 0; i < N-3; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf, yf+N-3);
		ans = min(ans, (xf[N-4].fst-xf[0].fst)*(yf[N-4].fst-yf[0].fst));
		
		for (int i = 1; i < N-2; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf+1, yf+N-2);
		ans = min(ans, (xf[N-3].fst-xf[1].fst)*(yf[N-3].fst-yf[1].fst));

		for (int i = 2; i < N-1; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf+2, yf+N-1);
		ans = min(ans, (xf[N-2].fst-xf[2].fst)*(yf[N-2].fst-yf[2].fst));

		for (int i = 3; i < N; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf+3, yf+N);
		ans = min(ans, (xf[N-1].fst-xf[3].fst)*(yf[N-1].fst-yf[3].fst));

		//2 from x
		
		for (int i = 0; i < N-2; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf, yf+N-2);

		for(int i = 1; i < N-2; i++)
			zf[i] = mp(yf[i].snd, yf[i].fst);
		sort(zf+1, zf+N-2);
		ans = min(ans, (zf[N-3].fst-zf[1].fst)*(yf[N-3].fst-yf[1].fst));

		for(int i = 0; i < N-3; i++)
			zf[i] = mp(yf[i].snd, yf[i].fst);
		sort(zf, zf+N-3);	
		ans = min(ans, (zf[N-4].fst-zf[0].fst)*(yf[N-4].fst-yf[0].fst));


		for (int i = 1; i < N-1; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf+1, yf+N-1);

		for(int i = 2; i < N-1; i++)
			zf[i] = mp(yf[i].snd, yf[i].fst);
		sort(zf+2, zf+N-1);
		ans = min(ans, (zf[N-2].fst-zf[2].fst)*(yf[N-2].fst-yf[2].fst));

		for(int i = 1; i < N-2; i++)
			zf[i] = mp(yf[i].snd, yf[i].fst);
		sort(zf, zf+N-2);	
		ans = min(ans, (zf[N-3].fst-zf[1].fst)*(yf[N-3].fst-yf[1].fst));


		for (int i = 2; i < N; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf+2, yf+N);

		for(int i = 3; i < N; i++)
			zf[i] = mp(yf[i].snd, yf[i].fst);
		sort(zf+3, zf+N);
		ans = min(ans, (zf[N-1].fst-zf[3].fst)*(yf[N-1].fst-yf[3].fst));

		for(int i = 2; i < N-1; i++)
			zf[i] = mp(yf[i].snd, yf[i].fst);
		sort(zf, zf+N-1);	
		ans = min(ans, (zf[N-2].fst-zf[2].fst)*(yf[N-2].fst-yf[2].fst));

		//3 from y
		for (int i = 0; i < N; i++){
			pii a = mp(xf[i].snd, xf[i].fst);
			xf[i] = a;
		}
		sort(xf, xf+N);

		for (int i = 0; i < N-3; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf, yf+N-3);
		ans = min(ans, (xf[N-4].fst-xf[0].fst)*(yf[N-4].fst-yf[0].fst));

		for (int i = 1; i < N-2; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf+1, yf+N-2);
		ans = min(ans, (xf[N-3].fst-xf[1].fst)*(yf[N-3].fst-yf[1].fst));

		for (int i = 2; i < N-1; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf+2, yf+N-1);
		ans = min(ans, (xf[N-2].fst-xf[2].fst)*(yf[N-2].fst-yf[2].fst));

		for (int i = 3; i < N; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf+3, yf+N);
		ans = min(ans, (xf[N-1].fst-xf[3].fst)*(yf[N-1].fst-yf[3].fst));

		//2 from y
		for (int i = 0; i < N-2; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf, yf+N-2);

		for(int i = 1; i < N-2; i++)
			zf[i] = mp(yf[i].snd, yf[i].fst);
		sort(zf+1, zf+N-2);
		ans = min(ans, (zf[N-3].fst-zf[1].fst)*(yf[N-3].fst-yf[1].fst));

		for(int i = 0; i < N-3; i++)
			zf[i] = mp(yf[i].snd, yf[i].fst);
		sort(zf, zf+N-3);	
		ans = min(ans, (zf[N-4].fst-zf[0].fst)*(yf[N-4].fst-yf[0].fst));


		for (int i = 1; i < N-1; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf+1, yf+N-1);

		for(int i = 2; i < N-1; i++)
			zf[i] = mp(yf[i].snd, yf[i].fst);
		sort(zf+2, zf+N-1);
		ans = min(ans, (zf[N-2].fst-zf[2].fst)*(yf[N-2].fst-yf[2].fst));

		for(int i = 1; i < N-2; i++)
			zf[i] = mp(yf[i].snd, yf[i].fst);
		sort(zf, zf+N-2);	
		ans = min(ans, (zf[N-3].fst-zf[1].fst)*(yf[N-3].fst-yf[1].fst));


		for (int i = 2; i < N; i++)
			yf[i] = mp(xf[i].snd, xf[i].fst);
		sort(yf+2, yf+N);

		for(int i = 3; i < N; i++)
			zf[i] = mp(yf[i].snd, yf[i].fst);
		sort(zf+3, zf+N);
		ans = min(ans, (zf[N-1].fst-zf[3].fst)*(yf[N-1].fst-yf[3].fst));

		for(int i = 2; i < N-1; i++)
			zf[i] = mp(yf[i].snd, yf[i].fst);
		sort(zf, zf+N-1);	
		ans = min(ans, (zf[N-2].fst-zf[2].fst)*(yf[N-2].fst-yf[2].fst));

	

		out << ans << endl;
	}

}

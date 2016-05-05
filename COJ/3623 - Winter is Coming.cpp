#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 1000020
#define MOD 167772161

typedef long long ll;

int p[MAXN];
ll c[1010];

ll inv(ll x){
	ll b = MOD-2;
	ll r = 1;

	for (; b; b /= 2){
		if (b % 2)
			r = (r * x) % MOD;
		x = (x * x) % MOD;
	}

	return r;
}

const ll mod = MOD;
const ll root = 625;
const ll root_1 = 15837692;
const ll root_pw = 1<<22;
 
void fft (vector<ll> & a, bool invert) {
	ll n = (ll) a.size();
 
	for (ll i=1, j=0; i<n; ++i) {
		ll bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (ll len=2; len<=n; len<<=1) {
		ll wlen = invert ? root_1 : root;
		for (ll i=len; i<root_pw; i<<=1)
			wlen = ll (wlen * 1ll * wlen % mod);
		for (ll i=0; i<n; i+=len) {
			ll w = 1;
			for (ll j=0; j<len/2; ++j) {
				ll u = a[i+j],  v = ll (a[i+j+len/2] * 1ll * w % mod);
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = ll (w * 1ll * wlen % mod);
			}
		}
	}
	if (invert) {
		ll nrev = inv(n);
		for (ll i=0; i<n; ++i)
			a[i] = ll (a[i] * 1ll * nrev % mod);
	}
}

void multiply (const vector<ll> & a, const vector<ll> & b, vector<ll> & res) {
	vector<ll> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
 
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] = (fa[i] * fb[i]) % MOD;
	fft (fa, true);
 
	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = ll (fa[i]) % MOD;
}

ll U, M, C;
vector<ll> a, b;

int main() {
	for (int i = 2; i < MAXN; i++)
		if(!p[i]){
			p[i] = i;
			for (ll j = i; j < MAXN; j += i)
				if(!p[j])
					p[j] = i;
		}

	scanf("%lld %lld %lld", &U, &M, &C);
	
	for (ll i = 2; i <= U; i++)
		if(p[i/p[i]] == i/p[i])
				c[i%M]++;

	for (int i = 0; i < M; i++)
		b.push_back(c[i]);
	a.push_back(1);
	
	ll K = C;
	for( ; K; K /= 2){
		if(K%2){
			multiply(a, b, a);
		}
		multiply(b, b, b);
	}

	printf("%lld\n", a[(C*M)/2]);
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll bpow(ll x, ll n, ll mod) {
	if (n == 0)return 1;
	ll t = bpow(x, n / 2, mod);
	if (n % 2 == 0)return t * t % mod;
	else return t * t % mod * x % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("SODU.inp", "r")) {
		freopen("SODU.inp", "r", stdin);
		freopen("SODU.out", "w", stdout);
	}

	ll a, b, c;
	cin >> a >> b >> c;
	cout << bpow(a, b, c);
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("PHATQUA.inp", "r")) {
		freopen("PHATQUA.inp", "r", stdin);
		freopen("PHATQUA.out", "w", stdout);
	}

	ll n, m;
	cin >> n >> m;

	ll x = __gcd(n, m);
	ll res = 0;
	for (ll i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			res++;
			if (i * i != x) res++;
		}
	}
	cout << res;
}

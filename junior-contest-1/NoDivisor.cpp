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

	if (fopen("NoDivisor.inp", "r")) {
		freopen("NoDivisor.inp", "r", stdin);
		freopen("NoDivisor.out", "w", stdout);
	}

	const ll mod = 1e9 + 7;
	ll n, res = 0;
	cin >> n;

	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res += i;
			if (i * i != n) {
				res += n / i;
			}
			res %= mod;
		}
	}

	if (n % 2 == 0) {
		cout << (n / 2 % mod * ((n + 1) % mod) % mod - res % mod + mod) % mod;
	}
	else {
		cout << ((n + 1) / 2 % mod * (n % mod) % mod - res % mod + mod) % mod;
	}
}

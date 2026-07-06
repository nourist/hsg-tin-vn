#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll fact[(int)2e5 + 5];
ll inv[(int)2e5 + 5];
ll invFact[(int)2e5 + 5];

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	fact[1] = inv[1] = invFact[1] = 1;
	FOR(i, 2, 2e5)fact[i] = fact[i - 1] * i % mod;
	FOR(i, 2, 2e5)inv[i] = mod - mod / i * inv[mod % i] % mod;
	FOR(i, 2, 2e5)invFact[i] = invFact[i - 1] * inv[i] % mod;

	int n;
	cin >> n;

	ll res = 1;
	FOR(i, 1, n)res = res * n % mod;


	res -= n;
	res -= 2 * (fact[n * 2 - 1] * invFact[n - 1] % mod * invFact[n] % mod - n);

	cout << (res % mod + mod) % mod;
}

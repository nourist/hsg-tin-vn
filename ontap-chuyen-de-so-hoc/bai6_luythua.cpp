#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll lt(ll x, ll n, ll m) {
	if (n == 0)return 1;
	if (n % 2 == 0) {
		ll t = lt(x, n / 2, m);
		return t * t % m;
	} else {
		return x * lt(x, n - 1, m) % m;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai6_luythua.inp", "r")) {
		freopen("bai6_luythua.inp", "r", stdin);
		freopen("bai6_luythua.out", "w", stdout);
	}

	ll n, a, b, c;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		cout << lt(a, lt(b, c, 1e9 + 6), 1e9 + 7) << '\n';
	}
}

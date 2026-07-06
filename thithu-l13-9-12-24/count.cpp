#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll lcm2(ll a, ll b) { return a / __gcd(a, b) * b; }
ll lcm3(ll a, ll b, ll c) { return lcm2(lcm2(a, b), c); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("count.inp", "r")) {
		freopen("count.inp", "r", stdin);
		freopen("count.out", "w", stdout);
	}

	ll n, p, q, r;
	while (cin >> n >> p >> q >> r) {
		ll res = 0;
		res += n / lcm2(p, q);
		res += n / lcm2(q, r);
		res += n / lcm2(r, p);
		res -= n / lcm3(p, q, r) * 3;
		cout << res << '\n';
	}
}

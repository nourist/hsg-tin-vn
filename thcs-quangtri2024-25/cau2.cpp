#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	ll n, m, h, v;
	cin >> n >> m >> h >> v;

	set<ll>a, b;

	for (int t, i = 0; i < h; i++) {
		cin >> t;
		a.insert(t);
	}
	for (int t, i = 0; i < v; i++) {
		cin >> t;
		b.insert(t);
	}
	a.insert(1);
	b.insert(1);
	a.insert(n + 1);
	b.insert(m + 1);

	ll x = *(++a.begin())-*a.begin();
	for (auto it = ++a.begin(); it != a.end(); it++) {
		auto prev = it;
		prev--;
		x = __gcd(x, *it - *prev);
	}
	for (auto it = ++b.begin(); it != b.end(); it++) {
		auto prev = it;
		prev--;
		x = __gcd(x, *it - *prev);
	}

	set<ll>res;
	for (ll i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			res.insert(i);
			res.insert(x / i);
		}
	}
	cout << res.size() << endl;
	for (ll i : res)
		cout << i << ' ';
}

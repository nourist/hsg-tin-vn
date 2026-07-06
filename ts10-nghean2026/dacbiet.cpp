#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll calc(ll n) {
	ll block = n / 70;
	ll du = n - block * 70;

	ll res = block * 7;
	res += min(du + 1, 7LL);

	return res - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("dacbiet.inp", "r")) {
		freopen("dacbiet.inp", "r", stdin);
		freopen("dacbiet.out", "w", stdout);
	}

	ll n, a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		cout << calc(b) - calc(a - 1) << '\n';
	}
}

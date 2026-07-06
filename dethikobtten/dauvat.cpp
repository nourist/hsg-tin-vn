#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll x[5], y[5];

ll solve() {
	ll res = 0;
	if (x[1] == y[1])res++;
	else if (x[1] > y[1])res += 3;

	if (x[2] == y[2])res++;
	else if (x[2] > y[2])res += 3;

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("dauvat.inp", "r")) {
		freopen("dauvat.inp", "r", stdin);
		freopen("dauvat.out", "w", stdout);
	}

	cin >> x[1] >> x[2] >> y[1] >> y[2];

	ll res = solve();
	swap(x[1], x[2]);
	res = max(res, solve());
	swap(y[1], y[2]);
	res = max(res, solve());
	swap(x[1], x[2]);
	res = max(res, solve());
	cout << res;
}

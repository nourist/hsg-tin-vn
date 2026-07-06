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

	if (fopen("lcm.inp", "r")) {
		freopen("lcm.inp", "r", stdin);
		freopen("lcm.out", "w", stdout);
	}

	ll t, l, r;
	cin >> t;
	while (t--) {
		cin >> l >> r;
		if (2 * l > r) cout << -1 << ' ' << -1 << '\n';
		else cout << l << ' ' << 2 * l << '\n';
	}
}

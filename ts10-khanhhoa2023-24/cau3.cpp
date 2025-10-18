#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(ll)1e6+10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	ll m, n;
	cin >> m >> n;

	for (ll i = 0; i < m; i++)cin >> a[i];
	sort(a, a + m, greater<ll>());
	ll res = 0, mi = 1e10;
	for (ll i = 0; i < min(n, m); i++) {
		mi = min(mi, a[i]);
		res = max(res, (i + 1) * mi);
	}
	cout << res;
}

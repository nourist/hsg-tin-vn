#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'

ll a[(ll)1e5 + 8], d[(ll)1e5 + 8];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	if (n == 0) {
		cout << -1;
		return 0;
	}
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	d[n - 1] = a[n - 1];
	for (ll i = n - 2; i >= 0; i--) {
		d[i] = min(a[i], d[i + 1]);
	}
	ll res = a[0] - d[1];
	for (ll i = 1; i < n - 1; i++) {
		res = max(res, a[i] - d[i + 1]);
	}
	if (res == 0) {
		cout << -1;
		return 0;
	}
	cout << max(-1LL, res);
}

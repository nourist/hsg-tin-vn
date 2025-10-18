#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e5 + 8], b[(int)1e5 + 8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai7.inp", "r")) {
		freopen("bai7.inp", "r", stdin);
		freopen("bai7.out", "w", stdout);
	}

	ll n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	while (k--) {
		int s;
		cin >> s;

		ll res = 1e9;
		ll l = 0, r = m - 1;
		while (l < n && r >= 0) {
			res = min(res, abs(s - a[l] - b[r]));
			if (a[l] + b[r] > s) {
				r--;
			}
			else {
				l++;
			}
		}

		cout << res << ' ';
	}
}

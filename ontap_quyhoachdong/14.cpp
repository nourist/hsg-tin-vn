#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		ll res1 = 0, res2 = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			res2 += max(0LL, a[i]);
			res1 = max(res1, sum);
			if (sum < 0)sum = 0;
		}
		bool alllo = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] >= 0)alllo = 0;
		}
		if (alllo)cout << *max_element(a, a + n) << ' ' << *max_element(a, a + n) << endl;
		else cout << res1 << ' ' << res2 << endl;
	}
}

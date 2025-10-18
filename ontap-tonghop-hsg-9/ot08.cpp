#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(ll)1e5 + 8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("nauan.inp", "r", stdin);
	freopen("nauan.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i], a[i] += a[i - 1];
	int q;
	cin >> q;
	while (q--) {
		int t; cin >> t;
		auto it = lower_bound(a + 1, a + n + 1, t);
		if (it == a + n + 1)cout << -1 << ' ';
		else cout << it - a << ' ';
	}
}

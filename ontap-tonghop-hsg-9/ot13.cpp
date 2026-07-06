#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "chenhlech"

int a[(int)1e5 + 5];
ll f[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, q, l, r, u, v;
	cin >> n >> q;

	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)f[i] = f[i - 1] + a[i];

	while (q--) {
		cin >> u >> v;
		l = u; r = v;
		ll res = 1e15;
		while (l <= r) {
			int mid = (l + r) / 2;
			ll sum1 = f[mid] - f[u - 1];
			ll sum2 = f[v] - f[mid];
			res = min(res, abs(sum1 - sum2));
			if (sum1 < sum2) l = mid + 1;
			else r = mid - 1;
		}
		cout << res << '\n';
	}
}
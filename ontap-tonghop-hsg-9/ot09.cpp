#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define name "phatsong"

struct cautruc {
	ll x, y;
} a[(ll)1e6 + 8];

ll d[(ll)1e6 + 8];

bool compare(cautruc x, cautruc y) {
	return x.x < y.x;
}

int main() {
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, k;
	cin >> n >> k;

	for (ll i = 0; i < n; ++i)
		cin >> a[i].x >> a[i].y;
	sort(a, a + n, compare);
	ll res = 0;
	ll bst = a[0].x;
	d[0] = a[0].y;
	for (ll i = 1; i < n; i++)bst = max(bst, a[i].x), d[i] = a[i].y + d[i - 1];
	for (ll i = 0; i < n; ++i) {
		int val = ((a[i].x - k < 0) ? a[i].x : a[i].x - k);
		cautruc st, ed;
		st.x = max(0LL, val - k);
		ed.x = val + k;
		res = max(res, max(0LL, d[upper_bound(a, a + n, ed, compare) - a - 1]) - d[lower_bound(a, a + n, st, compare) - a - 1]);
	}
	cout << res;
}

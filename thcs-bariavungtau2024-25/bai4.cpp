#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(ll)1e5 + 5], dp[(ll)1e5 + 5][2], st[(ll)4e5 + 5], lazy[(ll)4e5 + 5];

void fix(ll id, ll l, ll r) {
	if (!lazy[id]) return;
	st[id] += lazy[id];
	if (l != r) {
		lazy[id * 2] += lazy[id];
		lazy[id * 2 + 1] += lazy[id];
	}
	lazy[id] = 0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll val) {
	fix(id, l, r);
	if (v < l || u > r) return;
	if (u <= l && r <= v) {
		lazy[id] += val;
		fix(id, l, r);
		// st[id] = val;
		return;
	}

	ll mid = (l + r) / 2;
	update(id * 2, l, mid, u, v, val);
	update(id * 2 + 1, mid + 1, r, u, v, val);
	st[id] = max(st[id * 2], st[id * 2 + 1]);
}

ll get(ll id, ll l, ll r, ll u, ll v) {
	fix(id, l, r);
	if (v < l || u > r) return -1e9;
	if (u <= l && r <= v) return st[id];

	ll mid = (l + r) / 2;
	return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, k;
	cin >> n >> k;

	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dp[1][1] = a[1];
	update(1, 0, n, 0, 0, a[1]);
	for (ll i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
		update(1, 0, n, i - k + 1, i - 1, a[i]);
		dp[i][1] = max(dp[i][1], get(1, 0, n, i - k + 1, i - 1));
		update(1, 0, n, i, i, dp[i][0]);
	}
	cout << max(dp[n][0], dp[n][1]);
}

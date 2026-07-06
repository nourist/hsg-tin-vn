#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n;
int a[(int)3e5 + 5];

void compress() {
	map<int, int>mp;
	FOR(i, 1, n)mp[a[i]] = 1;

	int cnt = 1;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		it->second = cnt++;
	}

	FOR(i, 1, n)a[i] = mp[a[i]];
}

struct BIT {
	int bit[(int)3e5 + 5];

	void update(int idx, int v) {
		for (idx; idx <= 3e5; idx += (idx & (-idx)))bit[idx] += v;
	}

	int query(int idx) {
		int res = 0;
		for (idx; idx >= 1; idx -= (idx & (-idx))) res += bit[idx];
		return res;
	}
}l, r;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("seq.inp", "r")) {
		freopen("seq.inp", "r", stdin);
		freopen("seq.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	compress();

	FOR(i, 3, n)r.update(a[i], 1);
	l.update(a[1], 1);

	ll res = 0;

	FOR(i, 2, n - 1) {
		res += 1LL * l.query(a[i]) * r.query(a[i])
			+ 1LL * (l.query(n) - l.query(a[i] - 1)) * (r.query(n) - r.query(a[i] - 1))
			- 1LL * (l.query(a[i]) - l.query(a[i] - 1)) * (r.query(a[i]) - r.query(a[i] - 1));

		l.update(a[i], 1);
		r.update(a[i + 1], -1);
	}

	cout << res;
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, s;
int a[(int)1e6 + 6];
ll f[(int)1e6 + 6];
int bit[(int)1e6 + 6];

void update(int idx) {
	for (idx; idx <= 1e6; idx += (idx & (-idx)))bit[idx]++;
}

int query(int idx) {
	int res = 0;
	for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("dathiem.inp", "r")) {
		freopen("dathiem.inp", "r", stdin);
		freopen("dathiem.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	cin >> s;

	FOR(i, 1, n)a[i] -= s;
	FOR(i, 1, n)f[i] = f[i - 1] + a[i];

	{
		map<ll, int>mp;
		FOR(i, 0, n)mp[f[i]] = 1;

		int cnt = 1;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			it->second = cnt++;
		}

		FOR(i, 0, n)f[i] = mp[f[i]];
	}

	ll res = 0;
	update(f[0]);
	FOR(i, 1, n) {
		res += query(f[i]);
		update(f[i]);
	}
	cout << res;
}

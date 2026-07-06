#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "CLIS"

int n, x;
int a[(int)2e5 + 5];
int b[(int)2e5 + 5];
int r[(int)2e5 + 5];
int bit[(int)4e5 + 5];

void update(int idx, int v) {
	for (idx; idx <= 4e5; idx += (idx & (-idx))) bit[idx] = max(bit[idx], v);
}

int query(int idx) {
	int res = 0;
	for (idx; idx > 0; idx -= (idx & (-idx))) res = max(res, bit[idx]);
	return res;
}

void compress() {
	map<int, int>mp;
	FOR(i, 1, n)mp[a[i]] = mp[b[i]] = 1;

	int cnt = 1;
	for (auto it = mp.begin(); it != mp.end(); it++)it->Y = cnt++;

	FOR(i, 1, n) {
		a[i] = mp[a[i]];
		b[i] = mp[b[i]];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> x;

	FOR(i, 1, n) {
		cin >> a[i];
		b[i] = a[i] + x;
	}

	compress();

	FOD(i, n, 1) {
		int pos = 2 * n + 1 - b[i];
		r[i] = query(pos - 1) + 1;
		update(pos, r[i]);
	}

	memset(bit, 0, sizeof bit);

	int res = 0;
	FOR(i, 1, n) {
		res = max(res, query(b[i] - 1) + r[i]);
		update(a[i], query(a[i] - 1) + 1);
	}
	cout << res;
}
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, q, a[(int)3e5 + 5];

struct Bit {
	int bit[(int)3e5 + 5];
	bool mark[(int)3e5 + 5];

	void update(int idx, int value) {
		if (idx == 0)return;
		mark[idx] += value;
		for (idx; idx <= 3e5; idx += (idx & (-idx)))bit[idx] += value;
	}

	int query(int idx) {
		int res = 0;
		for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
		return res;
	}

	int queryRange(int l, int r) {
		return query(r) - query(l - 1);
	}
}odd, even;

void query1(int i, int j) {
	swap(a[i], a[j]);

	FOR(step, -1, 1) {
		int newI = i + step;
		int newJ = j + step;

		odd.update(newI, (a[newI - 1] == a[newI + 1]) - odd.mark[newI]);
		odd.update(newJ, (a[newJ - 1] == a[newJ + 1]) - odd.mark[newJ]);
	}

	FOR(step, -1, 0) {
		int newI = i + step;
		int newJ = j + step;

		even.update(newI, (a[newI] == a[newI + 1]) - even.mark[newI]);
		even.update(newJ, (a[newJ] == a[newJ + 1]) - even.mark[newJ]);
	}
}

void query2(int l, int r) {
	cout << ((even.queryRange(l, r - 1) + odd.queryRange(l + 1, r - 1)) == 0) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("APALIN.inp", "r")) {
		freopen("APALIN.inp", "r", stdin);
		freopen("APALIN.out", "w", stdout);
	}

	string s;
	cin >> n >> q >> s;

	FOR(i, 1, n) a[i] = s[i - 1];

	FOR(i, 2, n - 1) {
		if (a[i - 1] == a[i + 1]) {
			odd.update(i, 1);
		}
	}

	FOR(i, 1, n - 1) {
		if (a[i] == a[i + 1]) {
			even.update(i, 1);
		}
	}

	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1)query1(l, r);
		else query2(l, r);
	}
}

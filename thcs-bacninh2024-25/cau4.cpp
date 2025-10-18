#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int t, n, a[(int)1e5 + 5], l[(int)1e5 + 5], r[(int)1e5 + 5], bit[(int)1e5 + 5];

void update(int idx, int v) {
	for (idx; idx <= 1e5; idx += (idx & (-idx)))bit[idx] = max(bit[idx], v);
}

int query(int idx) {
	int res = 0;
	for (idx; idx >= 1; idx -= (idx & (-idx)))res = max(res, bit[idx]);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau4.inp", "r")) {
		freopen("cau4.inp", "r", stdin);
		freopen("cau4.out", "w", stdout);
	}

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)cin >> a[i];

		fill(bit, bit + (int)1e5 + 4, 0);
		for (int i = 1; i <= n; i++) {
			l[i] = query(a[i] - 1) + 1;
			update(a[i], l[i]);
		}

		fill(bit, bit + (int)1e5 + 4, 0);
		for (int i = n; i >= 1; i--) {
			r[i] = query(n - a[i]) + 1;
			update(n - a[i] + 1, r[i]);
		}

		int maxlen = query(n);
		set<int>s;
		for (int i = 1; i <= n; i++) {
			if (l[i] + r[i] - 1 == maxlen)s.insert(a[i]);
		}
		for (int i : s)cout << i << ' ';
		cout << endl;
	}
}
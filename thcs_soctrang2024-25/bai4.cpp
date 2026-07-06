#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, k, a[(int)1e6 + 6];
int st[(int)4e6 + 6];

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = a[l];
		return;
	}

	int mid = l + r >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int query(int id, int l, int r, int u, int v) {
	if (v<l || u>r)return 1e9;
	if (u <= l && v >= r)return st[id];

	int mid = l + r >> 1;
	return min(query(id * 2, l, mid, u, v), query(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	int n,k;
	cin >> n>>k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	build(1, 1, n);

	int res = -1e9;
	for (int i = 1; i <= n; i++) {
		res = max(res, a[i] - query(1, 1, n, i - k, i-1));
		// cout << query(1, 1, n, i - k, i - 1) << endl;
	}
	cout << res;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, m;
int a[(int)5e4 + 4];
pair<int, int>st[(int)2e5 + 5];

pair<int, int>merge(pair<int, int>a, pair<int, int>b) {
	return {min(a.first, b.first), max(a.second, b.second)};
}

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = {a[l], a[l]};
		return;
	}
	int mid = (l + r) >> 1;
	build(id *2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

pair<int, int>query(int id, int l, int r, int u, int v) {
	if (u > r || v < l) return { 1e9, -1e9 };
	if(u <= l && r <= v) return st[id];
	int mid = (l + r) >> 1;
	return merge(query(id * 2, l, mid, u, v), query(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("keoco.inp", "r")) {
		freopen("keoco.inp", "r", stdin);
		freopen("keoco.out", "w", stdout);
	}

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	build(1, 1, n);

	int l, r;
	while (m--) {
		cin >> l >> r;
		pair<int, int>res = query(1, 1, n, l, r);
		cout << res.second - res.first << '\n';
	}
}

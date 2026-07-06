#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, q,x,y;
pair<int, int>a[(int)1e5 + 5];
int st[(int)4e5 + 5];

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = a[l].second;
		return;
	}
	int mid = l + r >> 1;
	build(id*2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int query(int id, int l, int r, int u, int v) {
	if (r<u || l>v)return 0;
	if (u <= l && v >= r)return st[id];
	int mid = l + r >> 1;
	return max({
		query(id * 2,l,mid,u,v),
		query(id * 2 + 1,mid + 1,r,u,v)
		});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i].first >> a[i].second;

	sort(a + 1, a + n + 1);
	build(1, 1, n);

	cin >> q;
	while (q--) {
		cin >> x >> y;

		int l = lower_bound(a + 1, a + n + 1, make_pair(x, 0)) - a;
		int r = upper_bound(a + 1, a + n + 1, make_pair(y, (int)1e9)) - a - 1;
		cout << query(1, 1, n, l, r) << '\n';
	}
}
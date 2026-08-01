#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); ++i)
#define FOD(i,r,l) for (int i = (r); i >= (l); --i)
#define ll long long
#define db double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define BIT(x, i) (((x) >> (i)) & 1)
#define BIT_COUNT(x) __builtin_popcountll(x)
#define LOWEST_BIT(x) __builtin_ctzll(x)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "b1"

const int mod = 1e9 + 7;
int a[(int)2e5 + 5];
pii st[(int)8e5 + 5];// x : val, y: sum

pii operator + (pii x, pii y) {
	return { ((x.X + y.X) % mod + 1LL * x.Y * y.Y % mod) % mod, (x.Y + y.Y) % mod };
}

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = { 0, a[l] };
		return;
	}

	int mid = l + r >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(int id, int l, int r, int idx, int val) {
	if (idx<l || idx>r)return;

	if (l == r) {
		st[id] = { 0, val };
		return;
	}

	int mid = l + r >> 1;
	update(id * 2, l, mid, idx, val);
	update(id * 2 + 1, mid + 1, r, idx, val);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

pii query(int id, int l, int r, int u, int v) {
	if (r<u || l>v)return { 0, 0 };

	if (l >= u && r <= v) {
		return st[id];
	}

	int mid = l + r >> 1;
	return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, q;
	cin >> n >> q;
	FOR(i, 1, n)cin >> a[i];

	build(1, 1, n);

	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;

		if (t == 1) {
			update(1, 1, n, u, v);
		}
		else {
			cout << query(1, 1, n, u, v).X << endl;
		}
	}
}

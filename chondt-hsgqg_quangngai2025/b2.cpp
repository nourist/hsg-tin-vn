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
#define Name "b2"

int n;
int h[(int)1e5 + 5];
int p[(int)1e5 + 5];
int c[(int)1e5 + 5];

void compress() {
	vi v;
	FOR(i, 1, n)v.pb(h[i]);
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	FOR(i, 1, n)h[i] = lower_bound(all(v), h[i]) - v.begin() + 2;
}

struct SegTree {
	static const int MAXN = 100005;
	const ll NEG = -(1LL << 60);

	ll st[4 * MAXN];
	ll lazy[4 * MAXN];

	SegTree() {
		fill(st, st + 4 * MAXN, NEG);
		fill(lazy, lazy + 4 * MAXN, 0);
	}

	void fix(int id, int l, int r) {
		if (!lazy[id]) return;

		st[id] += lazy[id];

		if (l != r) {
			lazy[id * 2] += lazy[id];
			lazy[id * 2 + 1] += lazy[id];
		}

		lazy[id] = 0;
	}

	void update(int id, int l, int r, int u, int v, ll val) {
		fix(id, l, r);

		if (r < u || v < l) return;

		if (u <= l && r <= v) {
			lazy[id] += val;
			fix(id, l, r);
			return;
		}

		int mid = (l + r) >> 1;

		update(id * 2, l, mid, u, v, val);
		update(id * 2 + 1, mid + 1, r, u, v, val);

		st[id] = max(st[id * 2], st[id * 2 + 1]);
	}

	void setPoint(int id, int l, int r, int pos, ll val) {
		fix(id, l, r);

		if (l == r) {
			st[id] = val;
			return;
		}

		int mid = (l + r) >> 1;

		if (pos <= mid)
			setPoint(id * 2, l, mid, pos, val);
		else
			setPoint(id * 2 + 1, mid + 1, r, pos, val);

		st[id] = max(st[id * 2], st[id * 2 + 1]);
	}

	ll query(int id, int l, int r, int u, int v) {
		fix(id, l, r);

		if (r < u || v < l) return NEG;

		if (u <= l && r <= v)
			return st[id];

		int mid = (l + r) >> 1;

		return max(
			query(id * 2, l, mid, u, v),
			query(id * 2 + 1, mid + 1, r, u, v)
		);
	}
}lSeg, rSeg;

ll l[(int)1e5 + 5], r[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> h[i] >> p[i] >> c[i];

	compress();

	lSeg.setPoint(1, 1, n, 1, 0);
	rSeg.setPoint(1, 1, n, 1, 0);

	FOR(i, 1, n) {
		l[i] = lSeg.query(1, 1, n, 1, h[i]);
		lSeg.update(1, 1, n, h[i] + 1, n, c[i]);
		lSeg.update(1, 1, n, h[i], h[i], l[i] + p[i] + c[i] - lSeg.query(1, 1, n, h[i], h[i]));
	}

	FOD(i, n, 1) {
		r[i] = rSeg.query(1, 1, n, 1, h[i]);
		rSeg.update(1, 1, n, h[i] + 1, n, c[i]);
		rSeg.update(1, 1, n, h[i], h[i], r[i] + p[i] + c[i] - rSeg.query(1, 1, n, h[i], h[i]));
	}

	ll res = 0;
	FOR(i, 1, n) {
		res = max(res, l[i] + r[i] + p[i] + c[i]);
	}

	cout << res - accumulate(c + 1, c + n + 1, 0LL);
}

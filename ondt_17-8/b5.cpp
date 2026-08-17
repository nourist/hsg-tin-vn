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

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());

int t, n, m;
int a[(int)1e6 + 6];
int b[(int)1e6 + 6];

struct Fenwick {
	int bit[(int)2e6 + 6];

	void clear() {
		FOR(i, 0, n + m)bit[i] = 0;
	}

	void update(int idx, int val) {
		if (idx == 0)return;
		for (idx; idx <= n + m; idx += (idx & (-idx)))bit[idx] += val;
	}

	int queryL(int idx) {
		int res = 0;
		for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
		return res;
	}

	int queryR(int idx) {
		return queryL(n + m) - queryL(idx - 1);
	}
}lST, rST;

void compress() {
	vi pos;
	FOR(i, 1, n)pos.pb(a[i]);
	FOR(i, 1, m)pos.pb(b[i]);
	sort(all(pos));
	pos.erase(unique(all(pos)), pos.end());
	FOR(i, 1, n)a[i] = lower_bound(all(pos), a[i]) - pos.begin() + 1;
	FOR(i, 1, m)b[i] = lower_bound(all(pos), b[i]) - pos.begin() + 1;
}

ll res = 0;
void dfs(int l, int r, int opt_l, int opt_r) {
	if (l > r) return;
	int mid = l + r >> 1;
	pii bestMid = { 2e9, -1 };

	FOR(i, opt_l, opt_r + 1) {
		bestMid = min(bestMid, { lST.queryR(b[mid] + 1) + rST.queryL(b[mid] - 1), i });

		if (i <= opt_r && i <= n) {
			lST.update(a[i], 1);
			rST.update(a[i], -1);
		}
	}
	res += bestMid.X;

	FOR(i, opt_l, min(opt_r, n)) {
		lST.update(a[i], -1);
		rST.update(a[i], 1);
	}

	dfs(l, mid - 1, opt_l, bestMid.Y);

	FOR(i, opt_l, min(bestMid.Y - 1, n)) {
		lST.update(a[i], 1);
		rST.update(a[i], -1);
	}

	dfs(mid + 1, r, bestMid.Y, opt_r);

	FOR(i, opt_l, min(bestMid.Y - 1, n)) {
		lST.update(a[i], -1);
		rST.update(a[i], 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		FOR(i, 1, n)cin >> a[i];
		FOR(i, 1, m)cin >> b[i];

		sort(b + 1, b + m + 1);
		compress();
		lST.clear();
		rST.clear();
		FOR(i, 1, n)rST.update(a[i], 1);
		res = 0;
		dfs(1, m, 1, n);

		lST.clear();
		FOD(i, n, 1) {
			res += lST.queryL(a[i] - 1);
			lST.update(a[i], 1);
		}

		cout << res << endl;
	}
}
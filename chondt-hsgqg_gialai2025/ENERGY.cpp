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
#define Name "ENERGY"

int n;
pii a[(int)1e7 + 7];

struct BIT {
	int bit[(int)1e7 + 7];

	void update(int idx, int v) {
		if (idx == 0)return;
		for (idx; idx <= n; idx += (idx & (-idx)))bit[idx] += v;
	}

	void insert(int idx) {
		update(idx, 1);
	}

	void erase(int idx) {
		update(idx, -1);
	}

	int getOrder(int idx) {
		int res = 0;
		for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
		return res;
	}

	int getKey(int order) {
		int pos = 0;
		FOD(i, __lg(n), 0) {
			if (pos + (1 << i) <= n && bit[pos + (1 << i)] < order) {
				order -= bit[pos + (1 << i)];
				pos += (1 << i);
			}
		}
		return pos + 1;
	}
}pos, space;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i].X;
	FOR(i, 1, n)a[i].Y = i;

	sort(a + 1, a + n + 1, greater<pii>());

	int res = 1e9;
	FOR(i, 1, n) {
		pos.insert(a[i].Y);

		auto it = pos.getOrder(a[i].Y);

		if (it != 1 && it != i) {
			int l = pos.getKey(it - 1);
			int r = pos.getKey(it + 1);
			space.erase(r - l);
			space.insert(a[i].Y - l);
			space.insert(r - a[i].Y);
		}
		else if (it != 1) {
			int l = pos.getKey(it - 1);
			space.insert(a[i].Y - l);
		}
		else if (it != i) {
			int r = pos.getKey(it + 1);
			space.insert(r - a[i].Y);
		}

		int mx = space.getKey(space.getOrder(n));
		if (i != 1 && a[i].X >= mx) {
			res = min(res, mx);
		}
	}
	cout << (res == 1e9 ? 0 : res);
}

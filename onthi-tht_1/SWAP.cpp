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
#define Name "SWAP"

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());

struct Fenwick {
	int bit[(int)1e5 + 5];

	void update(int idx, int val) {
		for (idx; idx <= 1e5; idx += (idx & (-idx)))bit[idx] += val;
	}

	int query(int idx) {
		int res = 0;
		for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
		return res;
	}
}bit;

pii a[(int)1e5 + 5];
bool moved[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	FOR(i, 1, n)cin >> a[i].X;
	FOR(i, 1, n)a[i].Y = i;

	FOR(i, 1, n)bit.update(i, 1);

	sort(a + 1, a + n + 1, [&](pii x, pii y) {
		if (x.X == y.X)return x.Y < y.Y;
		return x.X > y.X;
		});

	vi res;

	FOR(i, 1, n) {
		int cnt = bit.query(a[i].Y - 1);
		if (cnt <= k) {
			k -= cnt;
			bit.update(a[i].Y, -1);
			res.pb(a[i].X);
			moved[a[i].Y] = 1;
		}
	}

	sort(a + 1, a + n + 1, [&](pii x, pii y) {
		return x.Y < y.Y;
		});

	FOR(i, 1, n)if (!moved[i])res.pb(a[i].X);
	for (int i : res)cout << i << ' ';
}
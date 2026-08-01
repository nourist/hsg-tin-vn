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
#define Name "inver"

int bit[(int)2e5 + 5];

void update(int idx) {
	if (idx == 0)return;
	for (idx; idx <= 2e5; idx += (idx & (-idx)))bit[idx]++;
}

int query(int idx) {
	int res = 0;
	for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
	return res;
}

int n;
int a[(int)2e5 + 5];
int id[(int)2e5 + 5];
ll prefix[(int)2e5 + 5];
ll suffix[(int)2e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)id[i] = i;

	sort(id + 1, id + n + 1, [&](int x, int y) {
		return a[x] < a[y];
		});

	FOR(i, 1, n) {
		prefix[i] = prefix[i - 1];

		int idx = id[i];

		prefix[i] += query(2e5) - query(idx);
		update(idx);
	}

	memset(bit, 0, sizeof bit);

	FOD(i, n, 1) {
		suffix[i] = suffix[i + 1];

		int idx = id[i];

		suffix[i] += query(idx);
		update(idx);
	}

	pll res = { 1e18,1e18 };
	FOR(i, 2, n - 1) {
		res = min(res, { prefix[i - 1] + suffix[i + 1], a[id[i]] });
	}
	cout << res.Y << ' ' << prefix[n] - res.X;
}

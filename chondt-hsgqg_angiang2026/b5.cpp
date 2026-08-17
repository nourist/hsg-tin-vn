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
#define Name "b5"

ll a[(int)1e5 + 5];
int l[(int)1e5 + 5];
int r[(int)1e5 + 5];
ll b[(int)1e5 + 5];
int id[(int)1e5 + 5];
ll suffix[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, m)cin >> b[i];

	b[0] = -3e9;
	b[m + 1] = 3e9;

	sort(b + 1, b + m + 1);

	FOR(i, 1, n) {
		r[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
		l[i] = r[i] - 1;
	}

	FOR(i, 1, n)id[i] = i;

	sort(id + 1, id + n + 1, [&](int x, int y) {
		return a[x] - b[l[x]] < a[y] - b[l[y]];
		});

	FOD(idx, n, 1) {
		int i = id[idx];

		suffix[idx] = max(suffix[idx + 1], b[r[i]] - a[i]);
	}

	ll res = suffix[1];
	FOR(idx, 1, n) {
		int i = id[idx];
		ll X = a[i] - b[l[i]];
		ll Y = suffix[idx + 1];

		res = min({ res, X * 2 + Y, X + Y * 2 });
	}

	cout << res;
}


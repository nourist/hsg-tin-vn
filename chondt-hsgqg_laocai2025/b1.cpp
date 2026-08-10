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

int n, m, k, u, v;
int a[6006][6006];
int f[6006][6006];

bool ok(int l) {
	FOR(i, l, n)FOR(j, l, m) {
		if (f[i][j] - f[i - l][j] - f[i][j - l] + f[i - l][j - l] <= v) {
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> m >> k >> u >> v;
	FOR(i, 1, k) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
	}

	FOR(i, 1, n)FOR(j, 1, m)f[i][j] = a[i][j];
	FOR(i, 1, n)FOR(j, 1, m)f[i][j] += f[i][j - 1];
	FOR(i, 1, n)FOR(j, 1, m)f[i][j] += f[i - 1][j];

	int l = 0, r = min(n, m) / u, res = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (ok(mid * u)) {
			res = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << res * u;
}

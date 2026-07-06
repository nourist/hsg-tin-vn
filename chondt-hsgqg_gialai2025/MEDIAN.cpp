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
#define Name "MEDIAN"

int n, m, r, c;
int a[1003][1003];
int f[1003][1003];

bool ok(int k) {
	FOR(i, 1, n)FOR(j, 1, m)f[i][j] = a[i][j] <= k;
	FOR(i, 1, n)FOR(j, 1, m)f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
	FOR(i, 1, n)FOR(j, 1, m) {
		if (i >= r && j >= c) {
			if (f[i][j] - f[i][j - c] - f[i - r][j] + f[i - r][j - c] >= (r * c + 1) / 2) {
				return 1;
			}
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

	cin >> n >> m >> r >> c;
	FOR(i, 1, n)FOR(j, 1, m)cin >> a[i][j];

	int l = 0, r = 1e9, res = 1e9;
	while (l <= r) {
		int mid = l + r >> 1;
		if (ok(mid)) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << res;
}
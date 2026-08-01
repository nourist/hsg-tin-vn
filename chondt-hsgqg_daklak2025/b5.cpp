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

int b[(int)1e5 + 5];
int a[(int)1e5 + 5][10];
int id[(int)1e5 + 5];
ll dp[(int)1e5 + 5][128];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, x, y;
	cin >> n >> x >> y;
	FOR(i, 1, n)cin >> b[i];
	FOR(i, 1, n)FOR(j, 0, x - 1)cin >> a[i][j];

	FOR(i, 1, n)id[i] = i;
	sort(id + 1, id + n + 1, [&](int x, int y) {
		return b[x] > b[y];
		});

	FOR(i, 0, n)
		FOR(mask, 0, (1 << x) - 1)
		dp[i][mask] = -1e18;

	dp[0][0] = 0;

	FOR(i, 1, n) {
		FOR(mask, 0, (1 << x) - 1)dp[i][mask] = dp[i - 1][mask];
		FOR(mask, 0, (1 << x) - 1) {
			int usedY = min(y, i - 1 - BIT_COUNT(mask));
			if (usedY != y)dp[i][mask] = max(dp[i][mask], dp[i - 1][mask] + b[id[i]]);
			FOR(j, 0, x - 1) {
				if (BIT(mask, j))continue;
				int newMask = TURNON(mask, j);
				dp[i][newMask] = max(dp[i][newMask], dp[i - 1][mask] + a[id[i]][j]);
			}
		}
	}
	ll res = 0;
	FOR(i, 1, n)res = max(res, dp[i][(1 << x) - 1]);
	cout << res;
}
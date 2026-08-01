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
#define Name "zeros"

ll a[202];
pii v[202];

pii factor(ll x) {
	pii res = { 0 ,0 };
	while (x % 2 == 0) {
		res.Y++;
		x /= 2;
	}
	while (x % 5 == 0) {
		res.X++;
		x /= 5;
	}
	return res;
}

int dp[202 * 26][202];

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
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)v[i] = factor(a[i]);

	sort(v + 1, v + n + 1, greater<pii>());

	int mx = 0;
	FOR(i, 1, k)mx += v[i].X;

	FOR(i, 0, mx)FOR(j, 0, k)dp[i][j] = -1e9;
	dp[0][0] = 0;

	FOR(i, 1, n)
		FOD(c, mx, 0)
		FOD(j, k, 0)
		dp[c + v[i].X][j + 1] = max(dp[c + v[i].X][j + 1], dp[c][j] + v[i].Y);

	int res = 0;
	FOR(i, 0, mx) {
		res = max(res, min(i, dp[i][k]));
	}
	cout << res;
}

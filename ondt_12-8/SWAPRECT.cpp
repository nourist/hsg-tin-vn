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
#define Name "SWAPRECT"

int a[202], b[202], c[202];
int dp[202][202][202];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m, p;
	cin >> n >> m >> p;

	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, m)cin >> b[i];
	FOR(i, 1, p)cin >> c[i];

	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	sort(c + 1, c + p + 1);

	FOR(i, 0, n)FOR(j, 0, m)FOR(k, 0, p) {
		dp[i][j][k] = max({
			(i > 0) ? dp[i - 1][j][k] : 0,
			(j > 0) ? dp[i][j - 1][k] : 0,
			(k > 0) ? dp[i][j][k - 1] : 0,
			(i > 0 && j > 0) ? dp[i - 1][j - 1][k] + a[i] * b[j] : 0,
			(j > 0 && k > 0) ? dp[i][j - 1][k - 1] + b[j] * c[k] : 0,
			(i > 0 && k > 0) ? dp[i - 1][j][k - 1] + a[i] * c[k] : 0
			});
	}

	cout << dp[n][m][p];
}

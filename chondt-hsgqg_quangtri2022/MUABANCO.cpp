#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); i++)
#define FOD(i,r,l) for (int i = (r); i >= (l); i--)
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
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "MUABANCO"

int a[(int)2e5 + 5];
ll dp[(int)2e5 + 5][111][2];

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

	FOR(i, 0, n)FOR(j, 0, k)dp[i][j][0] = dp[i][j][1] = -1e18;
	dp[0][0][1] = 0;
	FOR(i, 1, n)FOR(j, 0, k) {
		dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] - a[i]);
		dp[i][j][1] = dp[i - 1][j][1];
		if (j != 0)dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] + a[i]);
	}

	ll res = 0;
	FOR(i, 0, k)res = max(res, dp[n][i][1]);
	cout << res;
}

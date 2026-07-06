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
#define pib pair<int,bool>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vib vector<pib>
#define BIT(x, i) (((x) >> (i)) & 1)
#define MARK(x, i) ((x) | (1LL << (i)))
#define UNMARK(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "lamtron"

int a[2002], f[2002];
int dp[2002][202][10];
int g[2002][202][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, d;
	cin >> n >> d;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)f[i] = f[i - 1] + a[i];

	FOR(i, 1, n)FOR(j, 0, d)FOR(k, 0, 9)dp[i][j][k] = 1e9;
	FOR(i, 0, n)FOR(j, 0, d)FOR(k, 0, 9)g[i][j][k] = 1e9;
	g[0][0][0] = 0;

	FOR(i, 1, n) {
		if (i != 1)
			FOR(k, 0, 9)g[i][0][k] = g[i - 1][0][k];

		int cost = 0;
		if (f[i] % 10 < 5)cost = f[i] - f[i] % 10;
		else cost = f[i] + (10 - f[i] % 10);
		dp[i][0][f[i] % 10] = cost;

		g[i][0][f[i] % 10] = min(g[i][0][f[i] % 10], dp[i][0][f[i] % 10] - f[i]);
	}

	FOR(j, 1, d) {
		FOR(i, 1, n) {
			FOR(k, 0, 9)dp[i][j][k] = dp[i][j - 1][k];
			if (i != 1)
				FOR(k, 0, 9)g[i][j][k] = g[i - 1][j][k];

			FOR(k, 0, 9) {
				int add = (f[i] % 10 - k + 10) % 10;

				int delta;
				if (add < 5) delta = -add;
				else delta = 10 - add;

				dp[i][j][f[i] % 10] =
					min(dp[i][j][f[i] % 10],
						f[i] + delta + g[i - 1][j - 1][k]);
			}

			g[i][j][f[i] % 10] = min(g[i][j][f[i] % 10], dp[i][j][f[i] % 10] - f[i]);
		}
	}

	int res = 1e9;
	FOR(k, 0, 9)res = min(res, dp[n][d][k]);
	cout << res;
}

/*

dp[i][j][h]
số tiền nhỏ nhất để mua i món hàng ko dùng quá j thanh chia,
phan du cua tong la h

i: 1->n; j : 1->k

dp[i][j][h] = dp[i][j-1][h] // ko su dung thanh chia

x: 1 -> i
dp[i][j][h] = dp[k-1][j-1][f[k]] + f[i]-f[k-1]
dp[i][j][f[i]] = f[i] + min(dp[x-1][j-1][k] - f[x-1]) + add


 */
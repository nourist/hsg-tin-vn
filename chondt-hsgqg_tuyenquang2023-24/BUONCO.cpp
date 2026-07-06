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
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "BUONCO"

ll a[(int)1e6 + 6];
ll dp[(int)1e6 + 6][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	FOR(i, 0, n)dp[i][0] = dp[i][1] = dp[i][2] = -1e18;
	dp[0][0] = 0;

	FOR(i, 1, n) {
		dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - a[i]);
		dp[i][1] = max({ dp[i - 1][1], dp[i - 1][0] - a[i], dp[i - 1][2] + a[i] });
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
	}

	cout << max({ dp[n][0], dp[n][1], dp[n][2] });
}
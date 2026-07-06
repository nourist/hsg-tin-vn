#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll a[(int)1e5 + 5], w[102];
pair<ll,ll> dp[102][(int)1e5 + 5];

const ll mod = 1e9 + 7;

pair<ll, ll>merge(pair<ll, ll> a, pair<ll, ll> b) {
	if (a.first == b.first) {
		return make_pair( a.first, (a.second + b.second)%mod );
	}
	if (a.first > b.first) return a;
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("INVP.inp", "r")) {
		freopen("INVP.inp", "r", stdin);
		freopen("INVP.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, k)cin >> w[i];

	FOR(i, 1, k + 1)FOR(j, 0, n + 1)dp[i][j] = make_pair(-1e18, 1);
	FOR(j, 0, n + 1)dp[0][j] = make_pair(0, 1);

	FOR(i, 1, k) {
		FOR(j, i, n) {
			dp[i][j] = merge(dp[i][j-1], {dp[i - 1][j-1].first + a[j] * w[i], dp[i-1][j-1].second});
		}
	}
	cout<<dp[k][n].first%mod<<' '<<dp[k][n].second;
}

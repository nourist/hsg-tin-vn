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

ll a[505][505];
unordered_map<ll, ll> dp[505][505];

const ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	ll n, k;
	cin >> n >> k;
	FOR(i, 1, n)FOR(j, 1, n)cin >> a[i][j];
	dp[1][1][__gcd(a[1][1], k)] = 1;
	FOR(i, 1, n)FOR(j, 1, n)for (auto it : dp[i][j]) {
		ll d = it.X;
		if (a[i][j] == -1)dp[i][j][d] = 0;
		ll v = dp[i][j][d];
		v %= mod;
		if (i != n)dp[i + 1][j][__gcd(k, d * a[i + 1][j])] += v;
		if (j != n)dp[i][j + 1][__gcd(k, d * a[i][j + 1])] += v;
	}
	cout << dp[n][n][k] % mod;
}

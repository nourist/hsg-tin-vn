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
#define Name "dongxu"

int dp[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	ll n, m;
	cin >> n >> m;

	vector<ll>d;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			d.push_back(i);
			if (i * i != n)d.push_back(n / i);
		}
	}

	FOR(i, 1, 1e5)dp[i] = 1e9;
	for (ll x : d) {
		FOR(i, 0, 1e5 - x) {
			dp[i + x] = min(dp[i + x], dp[i] + 1);
		}
	}
	cout << dp[m];
}
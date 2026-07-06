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
#define Name "HAPPYPAR"

int a[(int)2e5 + 5];

const ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;
	FOR(i, 1, n)cin >> a[i];

	map<int, vi>mp;
	FOR(i, 1, n) {
		if (mp[a[i]].empty())mp[a[i]].pb(0);
		mp[a[i]].pb(i);
	}
	ll res = (1LL * n * (n - 1) / 2 + n) % mod * (1LL * m * (m + 1) / 2 % mod) % mod;
	for (auto it : mp) {
		it.Y.pb(n + 1);

		res -= (1LL * n * (n - 1) / 2 + n) % mod * it.X % mod;
		res = (res + mod) % mod;

		FOR(i, 1, it.Y.size() - 1) {
			int l = it.Y[i] - it.Y[i - 1] - 1;
			res += (1LL * l * (l - 1) / 2 + l) % mod * it.X % mod;
			res %= mod;
		}
	}

	cout << res;
}

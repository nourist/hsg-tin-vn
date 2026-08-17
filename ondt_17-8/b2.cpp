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
#define Name "b1"

int n;
const ll mod = 998244353;
ll a[(int)5e5 + 5], f[(int)5e5 + 5], s[(int)5e5 + 5];
ll pref[(int)5e5 + 5];
ll sufx[(int)5e5 + 5];

ll bpow(ll x, ll n) {
	ll res = 1;
	while (n != 0) {
		if (n % 2)
			res = (res * x) % mod;
		x = x * x % mod;
		n /= 2;
	}
	return res;
}

ll solve(int l) {
	ll sum = ((f[n] * (n - l + 1) % mod - pref[n - l] - sufx[l + 1]) % mod + mod) % mod;
	return sum * bpow(l, mod - 2) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		f[i] = (f[i - 1] + a[i]) % mod;
		pref[i] = (pref[i - 1] + f[i]) % mod;
	}

	FOD(i, n, 1) {
		s[i] = (s[i + 1] + a[i]) % mod;
		sufx[i] = (sufx[i + 1] + s[i]) % mod;
	}

	ll res = 0;
	FOR(i, 1, n) {
		res = (res + solve(i)) % mod;
	}
	cout << res;
}

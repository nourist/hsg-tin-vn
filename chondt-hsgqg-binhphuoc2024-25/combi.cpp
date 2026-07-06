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
#define Name "combi"

ll fact[(int)1e6 + 6];
ll inv[(int)1e6 + 6];
ll invFact[(int)1e6 + 6];

const ll mod = 1e9 + 7;

int n, q, l, r;
int a[(int)1e6 + 6];
int f1[(1 << 20) + 20];
int f2[(1 << 20) + 20];
ll g1[(1 << 20) + 20];
ll g2[(1 << 20) + 20];

ll bpow(ll x, ll n, ll mod) {
	if (n == 0)return 1;
	ll t = bpow(x, n / 2, mod);

	if (n % 2 == 0)return t * t % mod;
	return t * t % mod * x % mod;
}

ll cnk(int n, int k) {
	return fact[n] * invFact[k] % mod * (n - k < 0 ? 0 : invFact[n - k]) % mod;
}

ll Cnlr(int n) {
	ll res = 0;
	FOR(k, l, r)res += cnk(n, k);
	return res % mod;
}

ll s[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	fact[0] = 1;
	FOR(i, 1, 1e6)fact[i] = fact[i - 1] * i % mod;

	inv[1] = 1;
	FOR(i, 2, 1e6)inv[i] = mod - mod / i * inv[mod % i] % mod;

	invFact[0] = 1;
	FOR(i, 1, 1e6)invFact[i] = invFact[i - 1] * inv[i] % mod;

	cin >> n >> q >> l >> r;

	s[0] = Cnlr(0);
	FOR(i, 1, 1e6) {
		s[i] = s[i - 1] * 2 + cnk(i - 1, l - 1) - cnk(i - 1, r) + mod;
		s[i] %= mod;
	}

	FOR(i, 1, n)cin >> a[i];

	FOR(i, 1, n)f1[a[i]]++;
	FOR(i, 1, n)f2[a[i]]++;

	FOR(j, 0, 19)FOR(mask, 0, (1 << 20) - 1) {
		if (BIT(mask, j))continue;

		int newMask = TURNON(mask, j);

		f1[mask] += f1[newMask];
		f2[newMask] += f2[mask];
	}

	FOR(mask, 0, (1 << 20) - 1)g1[mask] = s[f1[mask]];
	FOR(mask, 0, (1 << 20) - 1)g2[mask] = s[f2[mask]];

	FOR(j, 0, 19)FOR(mask, 0, (1 << 20) - 1) {
		if (BIT(mask, j))continue;

		int newMask = TURNON(mask, j);

		g1[mask] = (g1[mask] - g1[newMask] + mod) % mod;
		g2[newMask] = (g2[newMask] - g2[mask] + mod) % mod;
	}

	FOR(i, 1, (1 << 20) - 1) {
		g1[i] += g1[i - 1];
		g2[i] += g2[i - 1];
	}

	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;

		if (t == 1) {
			cout << (g1[y] - g1[x - 1]) % mod << '\n';
		}
		else {
			cout << (g2[y] - g2[x - 1]) % mod << '\n';
		}
	}
}

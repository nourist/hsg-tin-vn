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
#define Name "b6"

vl primes;
void primeFactor(ll n) {
	ll i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			primes.push_back(i);
			while (n % i == 0) {
				n /= i;
			}
		}
		i++;
	}
	if (n != 1)primes.push_back(n);
}

ll f[(1 << 10) + 10];

ll solve(ll n) {
	ll res = 0;
	FOR(mask, 0, (1 << primes.size()) - 1) {
		res += n / f[mask];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	ll n, q, l, r;
	cin >> n >> q;

	primeFactor(n);

	FOR(mask, 0, (1 << primes.size()) - 1) {
		f[mask] = 1;
		FOR(i, 0, primes.size() - 1) {
			if (BIT(mask, i)) {
				f[mask] *= primes[i];
			}
		}
		if (BIT_COUNT(mask) % 2)f[mask] *= -1;
	}

	while (q--) {
		cin >> l >> r;
		cout << solve(r) - solve(l - 1) << endl;
	}
}

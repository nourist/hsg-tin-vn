#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (long long i = l; i <= r; ++i)
#define FOD(i,r,l) for (long long i = r; i >= l; --i)
#define ll long long
#define ld long double

ll n, q, l, r;
vector<ll>primes;

void build() {
	ll i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			primes.push_back(i);
		}
		i++;
	}
	if (n > 1) {
		primes.push_back(n);
	}
}

ll solve(ll m) {
	ll res = m;
	FOR(mask, 1, (1 << primes.size())-1) {
		ll mul = 1, cnt = 0;
		FOR(i, 0, primes.size() - 1) {
			if (mask & (1 << i)) {
				mul *= primes[i];
				cnt++;
			}
		}
		if (cnt % 2) {
			res -= m / mul;
		}
		else {
			res += m / mul;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai11_primequery.inp", "r")) {
		freopen("bai11_primequery.inp", "r", stdin);
		freopen("bai11_primequery.out", "w", stdout);
	}

	cin >> n >> q;
	build();
	while (q--) {
		cin >> l >> r;
		cout << solve(r) - solve(l - 1) << '\n';
	}
}

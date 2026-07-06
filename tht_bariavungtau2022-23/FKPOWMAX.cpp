#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll maxpow(ll n, ll k) {
	ll res = 0;
	for (ll i = k; i <= n; i *= k) {
		res += n / i;
	}
	return res;
}

vector < pair<ll, ll>> primeFactor(ll n) {
	vector<pair<ll, ll>>res;
	ll i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			res.push_back({ i,cnt });
		}
		i++;
	}
	if (n != 1)res.push_back({ n,1 });
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("FKPOWMAX.inp", "r")) {
		freopen("FKPOWMAX.inp", "r", stdin);
		freopen("FKPOWMAX.out", "w", stdout);
	}

	ll n, k;
	cin >> n >> k;
	ll res = 1e18;

	for (auto it : primeFactor(k)) {
		res = min(res, maxpow(n, it.first) / it.second);
	}

	cout << res;
}

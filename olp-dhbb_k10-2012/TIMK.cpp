#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "timk"

ll getk(ll n, ll m) {
	ll res = 0;
	for (ll i = m; i <= n; i *= m) {
		res += n / i;
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

	ll n, m;
	cin >> n >> m;

	unordered_map<ll, int>mp;
	{
		ll i = 2;
		while (i * i <= m) {
			while (m % i == 0) {
				mp[i]++;
				m /= i;
			}
			i++;
		}
		if (m != 1)mp[m]++;
	}

	ll res = 1e18;
	for (auto it : mp)res = min(res, getk(n, it.first) / it.second);
	cout << res;
}
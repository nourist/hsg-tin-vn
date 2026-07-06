#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(ll)5e5 + 10], d[(ll)5e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	ll n;
	cin >> n;

	unordered_map<ll, ll>mp;

	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = d[i - 1] + a[i];
	}

	ll res = -1e9;
	for (ll i = 1; i <= n; i++) {
		if (mp.find(a[i]) == mp.end())mp[a[i]] = i;
		if (d[mp[a[i]]] > d[i])mp[a[i]] = i;
		res = max(res, d[i] - d[mp[a[i]] - 1]);
	}
	cout << res;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(ll)1e6 + 1000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, k;
	cin >> n >> k;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		ll t = a[i];
		if (t > 0) {
			a[i] = t % k;
		}
		if (t < 0) {
			a[i] = (k - ((-t) % k)) % k;
		}
	}
	unordered_map<ll, ll>mp;
	ll res = 0;
	for (ll i = 0; i < n; i++) {
		if (a[i] == 0)res += mp[0];
		else
			res += mp[k - a[i]];
		mp[a[i]]++;
	}
	cout << res;
}

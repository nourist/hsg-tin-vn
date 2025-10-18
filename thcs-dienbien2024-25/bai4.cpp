#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	ll n,s;
	cin >> n>>s;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
		a[i]+=a[i-1];
	}

	vector<ll> d;

	d.push_back(0);
	
	ll res = 0;
	for (ll i = 1; i <= n; i++) {
		ll mi = a[i] - s;
		ll ma = a[i] + s;

		res += max(0LL, (ll)(lower_bound(d.begin(), d.end(), mi) - d.begin()));
		res += max(0LL, (ll)d.size() - (ll)(upper_bound(d.begin(), d.end(), ma) - d.begin()));
		

		d.insert(lower_bound(d.begin(), d.end(), a[i]), a[i]);
	}
	cout << res;
}

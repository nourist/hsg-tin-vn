#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("titeo.inp", "r")) {
		freopen("titeo.inp", "r", stdin);
		freopen("titeo.out", "w", stdout);
	}

	ll t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;

		ll x = k;
		ll y = k/n;
		while (y >0) {
			ll t = x / n;
			x += y;
			y = x / n - t;
		}
		cout << x<<'\n';
	}
}

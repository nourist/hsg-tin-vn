#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e5 * 2 + 8], d[(int)1e5 * 2 + 8];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cin >> a[0];
	d[0] = a[0];
	for (ll i = 1; i < n; i++) {
		cin >> a[i];
		d[i] = d[i - 1] + a[i];
	}

	ll ans = LONG_LONG_MAX;

	for (ll i = 0; i < n; i++) {
		ans = min(abs(d[n - 1] - d[i] * 2), ans);
	}

	cout << ans << endl;

}
//=)) 
//AC plzz

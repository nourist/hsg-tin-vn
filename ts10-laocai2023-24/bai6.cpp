#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(ll)1e5+10], d[(ll)1e5+10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai6.inp", "r")) {
		freopen("bai6.inp", "r", stdin);
		freopen("bai6.out", "w", stdout);
	}

	ll n, m;
	cin >> n >> m;
	for (ll i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	d[0] = a[0];
	for (ll i = 1; i < n; i++) {
		d[i] = d[i - 1] + a[i];
	}
	while (m--) {
		ll k, res = 0;
		cin >> k;
		ll it = upper_bound(a, a + n, k) - a-1;
		cout << (it + 1) * k - d[it] + d[n - 1] - d[it] - (n - it-1) * k<<endl;
	}
}

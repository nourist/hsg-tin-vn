#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(ll)1e6 + 8];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, cnt = 0, k;
	cin >> n >> k;

	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		cnt += a[i];
		a[i] += a[i - 1];
	}

	ll best = 0;
	for (ll i = k; i <= n; i++) {
		if (best < a[i] - a[i - k]) {
			best = a[i] - a[i - k];
		}
	}

	if (k - best <= cnt - best) {
		cout << k - best;
	}
	else cout << -1;
}
//=)) 
//AC plzz

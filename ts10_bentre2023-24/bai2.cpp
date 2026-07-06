#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll res = a[1];
	for (ll i = 2; i <= n; i++) {
		res ^= a[i];
	}
	cout << res;
}

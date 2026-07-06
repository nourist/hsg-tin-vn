#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("COUPLNUM.inp", "r")) {
		freopen("COUPLNUM.inp", "r", stdin);
		freopen("COUPLNUM.out", "w", stdout);
	}

	ll n;
	cin>>n;

	ll k = 1;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			k = max(k, i);
			k = max(k, n / i);
		}
	}
	cout << k << ' ' << n - k;
}

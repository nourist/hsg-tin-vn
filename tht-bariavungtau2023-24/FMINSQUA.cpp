#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("FMINSQUA.inp", "r")) {
		freopen("FMINSQUA.inp", "r", stdin);
		freopen("FMINSQUA.out", "w", stdout);
	}

	ll a, b;
	cin >> a >> b;
	for (ll i = 1; i <= 1e8; i++) {
		ll n = i * i;
		if (n % a == 0 && n % b == 0) {
			cout << n;
			return 0;
		}
	}
}

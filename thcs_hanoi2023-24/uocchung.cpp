#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("uocchung.inp", "r")) {
		freopen("uocchung.inp", "r", stdin);
		freopen("uocchung.out", "w", stdout);
	}

	ll a, b;
	cin >> a >> b;
	ll c = __gcd(a, b);
	if (c == 1)cout << -1;
	else {
		for (int i = 2; i <= sqrt(c); i++) {
			if (c % i == 0) {
				cout << c / i;
				return 0;
			}
		}
		cout << 1;
	}
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau1.inp", "r")) {
		freopen("cau1.inp", "r", stdin);
		freopen("cau1.out", "w", stdout);
	}

	ll a, b, c;
	cin >> a >> b >> c;
	ll res = 0;
	ll step = 1;
	for (ll x = 1; x <= c / a; x+=step) {
		ll sum = c - x * a;
		if (sum > 0 && sum % b == 0) {
			res++;
			step = b / __gcd(a, b);
		}
	}
	cout << res;
}

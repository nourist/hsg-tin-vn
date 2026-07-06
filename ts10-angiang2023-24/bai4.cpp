#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool ok(ll n) {
	if (n % 10 == 0)return 0;
	ll a = 0, t = n;
	while (t != 0) {
		a *= 10;
		a += t % 10;
		t /= 10;
	}
	return __gcd(a, n) == 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	ll a, b, res =0 ;
	cin >> a >> b;
	for (a; a <= b; a++) {
		if (ok(a)) {
			res ++ ;
			// cout << a << endl;
		}
	}
	cout << res;
}

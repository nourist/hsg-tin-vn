#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	ll x, y, n;
	cin >> x >> y >> n;
	a[1] = x;
	a[2] = y;
	const int mod = 1e9 + 7;
	for (int i = 3; i <= n; i++) {
		if (i % 2 == 0) {
			a[i] = (a[i - 1] + a[i - 2]) % mod;
		}
		else {
			a[i] = abs(a[i - 1] - a[i - 2]) % mod;
		}
	}
	cout << a[n];
}

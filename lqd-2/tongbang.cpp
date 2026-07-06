#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int mod = 1532023;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("tongbang.inp", "r")) {
		freopen("tongbang.inp", "r", stdin);
		freopen("tongbang.out", "w", stdout);
	}

	ll n, m;
	cin >> m >> n;

	if (n % 2 == 1) {
		ll x = ((n * m + 1) / 2)%mod;
		cout << (x * x)%mod;
	}
	else {
		ll x = (n/2 * m) %mod;
		cout << (x * (x + 1) + mod - ((m + 1) / 2 * (n / 2))%mod)%mod;
	}
}

/*

1 0  3  0
0 6  0  8
9 0  11 0

0 14 0 16

1 0 3
0 5 0
7 0 9

1 0  3  0
0 6  0  8
9 0  11 0
0 14 0 16

1 0  3
0 5  0
7 0  9
0 11 0

1+3+6+8+9+11+14+16 = 68
1+3+6+8+9+11=38

*/
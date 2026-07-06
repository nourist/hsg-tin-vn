#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

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
	ll np1 = n + 1;
	ll nm2p1 = n * 2 + 1;
	if (n % 2 == 0) {
		n /= 2;
	}
	else {
		np1 /= 2;
	}
	ll m2n = n * np1;
	if (nm2p1 % 3 == 0) {
		nm2p1 /= 3;
	}
	else {
		m2n /= 3;
	}
	nm2p1 %= 2018;
	m2n %= 2018;
	cout << (nm2p1 * m2n) % 2018;
}

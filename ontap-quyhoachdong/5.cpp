#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define name ""

ll fb[100];

ll nt(ll n) {
	for (ll i = 2; i * i <= n; i++)if (n % i == 0)return 0;
	return n > 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen(name".inp", "r", stdin);
	// freopen(name".out", "w", stdout);

	fb[1] = fb[2] = 1;
	for (ll i = 3; i <= 70; i++) {
	}
	ll n, res = 2;
	cin >> n;
	for (ll i = 3; i <= 70; i++) {
		fb[i] = fb[i - 1] + fb[i - 2];
		if (fb[i] > n)break;
		if (nt(fb[i]))res = fb[i];
	}
	cout << res;
}

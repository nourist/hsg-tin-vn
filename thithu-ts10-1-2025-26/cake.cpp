#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cake.inp", "r")) {
		freopen("cake.inp", "r", stdin);
		freopen("cake.out", "w", stdout);
	}

	ll t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 1)cout << 0 << '\n';
		else cout << (n & 1 ? n : n / 2) << '\n';
	}
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("biendoi.inp", "r")) {
		freopen("biendoi.inp", "r", stdin);
		freopen("biendoi.out", "w", stdout);
	}

	ll t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;

		if (a == b)cout << 0 << '\n';
		if (a > b) {
			if (a % 2 == b%2)cout << 1 << '\n';
			else cout << 2 << '\n';
		}
		else {//a < b
			if(a % 2 == b % 2)cout << 2 << '\n';
			else cout << 1 << '\n';
		}
	}
}

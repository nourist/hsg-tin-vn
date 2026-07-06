#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p(ll n) {
	for (ll i = 2; i * i <= n; i++)if (n % i == 0)return 0;
	return n > 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	ll n, m;
	cin >> n >> m;
	ll s = 1;
	for (ll i = 1; s <= m; i++) {
		s *= i;
		if (s >= n && s <= m) {
			if (p(s - 1))cout << s - 1 << endl;
			if (p(s))cout << s << endl;
			if (p(s + 1)&&s+1<=m)cout << s + 1 << endl;
		}
	}
}

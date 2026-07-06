#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	ll n, res = 1;
	cin >> n;
	if (n <= 1) {
		cout << 0;
		return 0;
	}
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res += i;
			if (i * i != n)res += n / i;
		}
	}
	cout << res;
}

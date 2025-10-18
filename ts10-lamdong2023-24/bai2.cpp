#include <bits/stdc++.h>
using namespace std;

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
	cout << n * (n + 1) / 2 * (2 * n + 1) / 3 << ' ';
	ll res = 0;
	for (ll i = 1; i <= n; i++) {
		res += i * (n - i + 1);
	}
	cout << res;
}

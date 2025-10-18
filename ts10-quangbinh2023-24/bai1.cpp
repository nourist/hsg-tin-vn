#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll sum(ll n) {
	if (n <= 100)return n * 1700;
	if (n <= 150)return 100 * 1700 + (n - 100) * 1900;
	if (n <= 200)return 100 * 1700 + 50 * 1900 + (n - 150) * 2100;
	return 100 * 1700 + 50 * 1900 + 50 * 2100 + (n - 200) * 2500;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	ll x, y;
	cin >> x >> y;
	cout << sum(x-y);
}

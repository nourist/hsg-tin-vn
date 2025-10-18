#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll x, y;
	cin >> x >> y;
	//    cout << __gcd(x,y);
	ll n = __gcd(x, y);

	ll res = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res += 2;
			res -= i * i == n;
		}
	}
	cout << res;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define __lcm(a,b) (a/__gcd(a,b)*b)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	ll n, m;
	cin >> n >> m;

	if (m % n != 0) {
		cout << -1;
		return 0;
	}

	ll x = m/n;

	ll res = 1e14;
	for (ll i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			ll a = i, b = x / i;
			if(__gcd(a,b)==1)
			res = min(res, n*(i + x / i));
		}
	}
	cout << (res==1e14?-1:res);
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e6 + 10];
const int mod = (int)1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	ll n, k, p;
	cin >> n >> k >> p;

	p--;

	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
		s %= mod;
	}

	ll res = s * ((k / n)%mod)%mod;
	k %= n;
	p %= n;
	for (int i = p; i < p + k; i++) {
		res += a[i % n];
		res %= mod;
	}
	cout << res;
}

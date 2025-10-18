#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll bpow(ll x, ll n) {
	if (n == 1)return x;
	else {
		ll t = bpow(x, n / 2);
		if (n % 2 == 0)return t * t;
		else return t * t * x;
	}
}

ll solve(ll n, ll idx) {
	if (n == 0)return 0;
	if (n == 1)return 1;
	ll s = sqrt(n);
	s *= s;

	return bpow(s,idx) + solve(n - s, idx+1);
}

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
	cout << solve(n,1);
}

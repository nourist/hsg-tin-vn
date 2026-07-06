#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("RTRIANG.inp", "r")) {
		freopen("RTRIANG.inp", "r", stdin);
		freopen("RTRIANG.out", "w", stdout);
	}

	ll n;
	cin >> n;

	ll res = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = i + 1; i * i + j * j <= n && 2 * i * j <= n; j+=2) {
			if (__gcd(i, j) >1)continue;
			ll a = j * j - i * i;
			ll b = i * j * 2;
			ll c = i * i + j * j;
			if (n % (a + b + c) == 0)res++;
		}
	}
	cout << res;
}

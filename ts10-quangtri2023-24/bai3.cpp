#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool prime0(ll n){
	for (ll i = 2; i * i <= n; i++)if (n % i == 0)return 0;
	return n > 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	ll n, l, r;
	vector<ll>res;
	cin >> n >> l >> r;

	for (l; l <= r; l++) {
		if (prime0(__gcd(n, l)))res.push_back(l);
	}
	cout << res.size() << endl;
	for (ll i : res)cout << i << ' ';
}

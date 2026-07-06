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

	ll n, d, k;
	cin >> n >> d >> k;

	ll t = 0;
	ll res = 1;
	for (int i = 1; i <= k; i++) {
		t += d;
		t %= n;
		res += t + 1;
	}
	cout << res;
}

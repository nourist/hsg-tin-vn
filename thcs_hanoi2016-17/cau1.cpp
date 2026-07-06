#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll d[(ll)1e6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau1.inp", "r")) {
		freopen("cau1.inp", "r", stdin);
		freopen("cau1.out", "w", stdout);
	}

	for (ll i = 1; i <= 1e6; i++) {
		for (ll j = i; j <= 1e6; j += i)
			d[j]++;
	}

	ll n, k, res = 0;
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		res += d[i] == k;
	}
	cout << res;
}

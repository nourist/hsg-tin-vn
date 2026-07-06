#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll n, a[(ll)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	cin >> n;
	for (ll i = 0; i < n; i++)cin >> a[i];
	ll mi = 1e9, res = 0;
	for (ll i = 0; i < n; i++) {
		mi = min(mi, a[i]);
		res += mi * 3;
	}
	cout << res;
}

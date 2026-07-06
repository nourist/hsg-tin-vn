#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e6 + 9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i], a[i] += a[i - 1];

	ll res = LONG_LONG_MAX;
	for (int i = 1; i <= n; i++) {
		ll sum = a[n] - a[i];
		res = min(res, abs(a[i] - sum));
	}
	cout << res;
}

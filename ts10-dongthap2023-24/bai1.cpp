#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	ll n, res = 0;
	cin >> n;
	int l = 0, r = 6e6;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (mid * (mid + 1) / 2 * (2 * mid + 1) / 3 <= n)res = max(res, mid), l = mid + 1;
		else r = mid - 1;
	}
	cout << res;
}
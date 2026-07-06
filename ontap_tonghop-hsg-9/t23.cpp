#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(ll)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("cotnuoc.inp", "r", stdin);
	freopen("cotnuoc.out", "w", stdout);

	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)cin >> a[i];

	ll l = 0, r = n - 1, lm = a[0], rm = a[n - 1], res = 0;
	while (l < r) {
		if (lm < rm) {
			l++;
			lm = max(lm, a[l]);
			res += lm - a[l];
		}
		else {
			r--;
			rm = max(rm, a[r]);
			res += rm - a[r];
		}
	}

	cout << res;
}

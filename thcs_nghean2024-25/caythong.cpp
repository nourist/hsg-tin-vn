#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll n;
ll a[(ll)1e5 + 100], b[(ll)1e5 + 100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("caythong.INP", "r", stdin);
	freopen("caythong.OUT", "w", stdout);

	cin >> n;

	for (ll i = 0; i < n; i++)cin >> a[i];
	for (ll i = 0; i < n; i++)cin >> b[i];

	sort(a, a + n);
	sort(b, b + n);

	ll l = 0, r = n - 1;
	ll res = 1e18;
	while (l < n && r >= 0) {
		ll sum = a[l] + b[r];
		res = min(res, abs(sum));
		if (sum > 0)r--;
		else l++;
	}
	cout << res;
}


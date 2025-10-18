#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define name "taoday"

const ll limit = 1e6 + 8;
ll a[limit], b[limit], c[limit];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);

	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)cin >> a[i];
	for (ll i = 0; i < n; i++)cin >> b[i];
	c[0] = a[0] * b[0];
	for (ll i = 1; i < n; i++) {
		a[i] = max(a[i - 1], a[i]);
		c[i] = max(c[i - 1], a[i] * b[i]);
	}
	for (ll i = 0; i < n; i++)cout << c[i] << '\n';
}

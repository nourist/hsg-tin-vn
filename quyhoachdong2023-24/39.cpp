#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(ll)1e5 + 10];
ll d1[(ll)1e5 + 10];
ll d2[(ll)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("DPMAXFX.inp", "r", stdin);
	freopen("DPMAXFX.out", "w", stdout);

	int n;
	cin >> n;

	fill(d1, d1 + (int)1e5 + 10, -1e9);
	fill(d2, d2 + (int)1e5 + 10, -1e9);

	for (int i = 1; i <= n; i++)cin >> a[i], d1[i] = max(d1[i - 1], a[i]);
	for (int i = n; i >= 1; i--) d2[i] = max(d2[i + 1], a[i]);
	ll res = -1e18;
	for (int i = 2; i <= n - 1; i++) {
		res = max(res, d1[i - 1] + a[i] * 2 + d2[i + 1] * 3);
	}
	cout << res;
}

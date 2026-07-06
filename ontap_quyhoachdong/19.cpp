#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e4 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("dprince.inp", "r", stdin);
	freopen("dprince.out", "w", stdout);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)cin >> a[i];
		for (int i = 2; i <= n; i++) {
			a[i] = max(a[i - 2] + a[i], a[i - 1]);
		}
		cout << a[n] << endl;
	}
}

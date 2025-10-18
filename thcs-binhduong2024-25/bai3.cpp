#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[(ll)1e6 + 6];
ll f[(ll)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}

	if (f[n] % 3 != 0) {
		cout << 0;
		return 0;
	}

	ll res = 0, cnt =0;

	for (int i = 1; i < n; i++) {
		if (f[i] * 3 == f[n] * 2)res += cnt;
		if (f[i] * 3 == f[n])cnt++;
	}
	
	cout << res;
}

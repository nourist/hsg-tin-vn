#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("cau3.inp", "r", stdin);
	// freopen("cau3.out", "w", stdout);

	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)cin >> a[i];
	ll res = 0, cnt = 0, sum = 0;
	for (ll i = 0; i < n; i++) {
		if (a[i] == 0) {
			cnt++;
		}
		else {
			sum++;
			cnt--;
		}
		res = max(res, cnt);
		if (cnt < 0)cnt = 0;
	}
	cout << sum + res;
}

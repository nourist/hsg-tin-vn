#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const ll limit = 1e6;
ll a[limit + 100], d[limit + 100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, k;
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) cin >> a[i], d[i] = a[i];
	for (ll i = 2; i <= n; i++) d[i] += d[i - 1];

	ll l = 0, r = k - 1, ans = -1;
	for (ll i = 1; i + k - 1 <= n; i++) {
		if (d[i + k - 1] - d[i - 1] > ans) {
			ans = d[i + k - 1] - d[i - 1];
			l = i - 1;
			r = i + k - 1;
		}
	}
	cout << ans << endl;
	for (l; l < r; l++) {
		cout << l << ' ';
	}
}

//=)) 
//AC plzz

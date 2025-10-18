#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

pair<ll, ll>a[(ll)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai5.inp", "r")) {
		freopen("bai5.inp", "r", stdin);
		freopen("bai5.out", "w", stdout);
	}

	ll n, m;
	cin >> n >> m;

	for (ll i = 1; i <= n; i++)cin >> a[i].second >> a[i].first;
	sort(a + 1, a + n + 1, greater<pair<ll, ll>>());
	ll res = 0;
	for (ll i = 1; i <= n; i++) {
		ll nums = min(m, a[i].second);
		res += nums * a[i].first;
		m -= nums;
		if(m<=0)break;
	}
	cout << res;
}

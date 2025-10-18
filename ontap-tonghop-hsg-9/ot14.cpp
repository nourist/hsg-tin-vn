#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define name "gcdmax"

ll a[(ll)1e5 + 8];

deque<ll> dq;

ll gcd() {
	ll res = *dq.begin();
	for (auto it = dq.begin(); it != dq.end(); it++) {
		res = __gcd(res, *it);
		if (res == 1)break;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);

	ll n, k;
	cin >> n >> k;
	for (ll i = 0; i < n; i++)cin >> a[i];
	for (ll i = k; i < n; i++)dq.push_back(a[i]);
	ll res = gcd();
	for (ll i = k; i < n; i++) {
		dq.pop_front();
		dq.push_back(a[i - k]);
		res = max(res, gcd());
	}
	cout << res;
}

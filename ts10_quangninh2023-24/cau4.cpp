#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll d[(ll)1e6 + 10];
bool c[(ll)1e6 + 10];
ll e[(ll)1e6 + 10];

string str;

bool ok(ll l) {
	memset(c, 0, sizeof c);

	for (ll i = l; i <= str.size(); i++) {
		ll sum = d[i] - d[i - l];
		if (c[sum])return 1;
		else c[sum] = 1;
	}
	return 0;
}

void query() {
	fill(d, d + (ll)1e6, 0);
	fill(e, e + (int)1e6, 0);

	for (ll i = 1; i <= str.size(); i++) {
		d[i] = d[i - 1] + (str[i - 1] - '0');
	}

	ll l = 1, r = str.size() - 1, res = -1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (ok(mid)) {
			res = max(res, mid);
			l = mid + 1;
		}
		else { r = mid - 1; }
	}
	if (res != -1) {
		for (ll i = res; i <= str.size(); i++) {
			ll sum = d[i] - d[i - res];
			if (e[sum] == 0)e[sum] = i;
			else {
				cout << e[sum] - res + 1 << ' ' << e[sum] << ' ' << i - res + 1 << ' ' << i << endl;
				return;
			}
		}
	}
	else {
		cout << -1 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin >> t;
	while (t--) {
		cin >> str;
		query();
	}
}

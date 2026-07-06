#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (ll i = l; i <= r; i++)
#define FOD(i,r,l) for (ll i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "bansung"

ll n, k;
ll a[(ll)2e5 + 5], d1[(ll)2e5 + 5], d2[(ll)2e5 + 5], d3[(ll)2e5 + 5];

bool ok(ll x) {
	FOR(i, 1, n)d1[i] = d2[i] = d3[i] = 0;

	ll cnt = 0;
	FOR(i, 1, n) {
		d1[i] += d1[i - 1];
		d2[i] += d2[i - 1];
		d3[i] += d3[i - 1];

		ll cur = a[i] - (x * d1[i] - i * i * d1[i] + 2 * i * d2[i] - d3[i]);

		if (cur <= 0)continue;

		ll shots = (cur + x - 1) / x;
		cnt += shots;

		ll l = i + 1;
		ll r = min(n + 1, (ll)sqrt(x - 1) + i);

		d1[l] += shots;
		d1[r + 1] -= shots;
		d2[l] += shots * i;
		d2[r + 1] -= shots * i;
		d3[l] += shots * i * i;
		d3[r + 1] -= shots * i * i;
	}

	return cnt <= k;
}

/*
x - (j-i)^2
j^2 - 2ij + i^2

a - (x - j^2 + 2ij - i*2)

x - (j-i)^2>=0
x>=(j-i)^2
sqrt(x)>=j-i
sqrt(x)+i>=j
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> k;
	FOR(i, 1, n)cin >> a[i];

	ll l = 0, r = 1e18, res = 1e18;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (ok(mid)) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << res;
}
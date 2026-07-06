#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "bai2"

ll n, x, k;
string s;

ll getSum(ll r) {
	ll res = 0;
	FOR(i, 1, r) {
		if (s[i - 1] == 'L') {
			res--;
		}
		else {
			res++;
		}
	}
	return res;
}

bool isReturnTo0() {
	ll cur = x;
	FOR(i, 1, n) {
		if (s[i - 1] == 'L')cur--;
		else cur++;

		if (cur == 0)return 1;
	}

	if (x < 0 && getSum(n)>0)return 1;
	if (x > 0 && getSum(n) < 0)return 1;
	return 0;
}

ll returnTo0After(ll cur = x) {
	ll cnt = 0;

	if (cur == 0)return cnt;

	FOR(i, 1, n) {
		if (s[i - 1] == 'L')cur--;
		else cur++;

		cnt++;

		if (cur == 0)return cnt;
	}

	cnt = abs(cur) / abs(getSum(n)) * n;
	cur %= abs(getSum(n));

	return returnTo0After(cur) + cnt;
}

bool isLoopTo0() {
	ll cur = 0;
	FOR(i, 1, n) {
		if (s[i - 1] == 'L')cur--;
		else cur++;

		if (cur == 0)return 1;
	}
	return 0;
}

ll loopTo0After() {
	ll cur = 0;
	FOR(i, 1, n) {
		if (s[i - 1] == 'L')cur--;
		else cur++;

		if (cur == 0)return i;
	}
}

void solve() {
	cin >> n >> x >> k >> s;

	if (!isReturnTo0()) {
		cout << 0 << ' ' << x + getSum(n) * (k / n) + getSum(k % n) << endl;
		return;
	}

	if (k < returnTo0After()) {
		cout << 0 << ' ' << x + getSum(n) * (k / n) + getSum(k % n) << endl;
		return;
	}

	k -= returnTo0After();
	x = 0;

	if (!isLoopTo0()) {
		cout << 1 << ' ' << x + getSum(n) * (k / n) + getSum(k % n) << endl;
		return;
	}

	cout << 1 + k / loopTo0After() << ' ' << getSum(k % loopTo0After()) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int t;
	cin >> t;

	while (t--)solve();
}
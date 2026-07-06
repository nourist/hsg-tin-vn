#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll mul(ll x, ll n) {
	if (n == 0)return 1;
	return x * mul(x, n - 1);
}

ll solve(ll n) {
	string s = to_string(n);
	int sz = s.size();

	if (sz == 1) {
		return s[0] - '0';
	}
	if (sz == 2) {
		return 9 + s[0] - '0' - 1+(s[1]>=s[0]);
	}

	ll res = 0;

	FOR(len, 1, sz - 1) {
		if (len == 1)res += 9;
		else res += (ll)mul(10, len - 2)*9;
	}

	res += (s[0] - '0' - 1) * (ll)mul(10, sz - 2);

	if (s[0] >= s[sz - 1]) {
		res += stoll(s.substr(1, sz - 2))+1;
	}
	else {
		res += stoll(s.substr(1, sz - 2));
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	ll l, r;
	cin >> l >> r;

	cout << solve(r) - solve(l - 1);
}

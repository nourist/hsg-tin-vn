#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll n, s;
ll a[(ll)1e5 + 5];
ll suffix[(ll)1e5 + 5];
ll prefix[(ll)1e5 + 5];
ll bit[(ll)2e5 + 5];
map<ll, ll>mp;

ll query(ll idx) {
	idx = mp[idx];
	ll res = 1e9;
	for (idx; idx >= 1; idx -= (idx & (-idx)))res = min(res, bit[idx]);
	return res;
}


void update(ll idx, ll v) {
	idx = mp[idx];
	for (idx; idx <= 2e5; idx += (idx & (-idx)))bit[idx] = min(bit[idx], v);
}

void compress() {
	FOR(i, 0, n) {
		mp[suffix[i + 1]] = 1;
		mp[s - prefix[i]] = 1;
	}

	ll cnt = 1;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		it->second = cnt++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("xoadoan.inp", "r")) {
		freopen("xoadoan.inp", "r", stdin);
		freopen("xoadoan.out", "w", stdout);
	}

	FOR(i, 1, 2e5)bit[i] = 1e9;

	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	cin >> s;

	FOR(i, 1, n)prefix[i] = prefix[i - 1] + a[i];
	FOD(i, n, 1)suffix[i] = suffix[i + 1] + a[i];

	compress();

	ll res = 1e9;

	FOD(i, n, 0) {
		update(suffix[i + 1], i + 1);

		ll j = query(s - prefix[i]);

		if (j == 1e9)continue;

		res = min(res, j - i - 1);
	}

	if (res == 1e9)cout << -1;
	else cout << res;
}

/*
s1+s3<=s
s3<=s-s1
*/
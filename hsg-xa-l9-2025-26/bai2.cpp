#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	ll l, r, x;
	cin >> l >> r >> x;

	vector<ll>res;
	for (ll i = 1; i <= r; i *= x) {
		if (i >= l) res.push_back(i);
	}

	if (res.size() == 0) cout << -1;
	else {
		for (auto i : res) cout << i << " ";
	}
}

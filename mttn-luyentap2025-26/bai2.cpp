#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll next(ll x) {
	if (x % 2 == 0) {
		string a = to_string(x);
		string b = to_string(x);

		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), greater<int>());

		x = stoll(b) - stoll(a);
	}
	else {
		string a = to_string(x);
		sort(a.begin(), a.end());
		x = x - stoll(a);
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	ll x, k;
	cin >> x >> k;

	unordered_map<ll, ll>mp;
	vector<ll>a;

	a.push_back(0);
	a.push_back(x);
	mp[x] = 1;

	pair<ll, ll>cycle = { 0, 0 };

	FOR(i, 2, k + 1) {
		x = next(x);
		if (mp[x] != 0) {
			cycle = { mp[x], i - 1 };
			break;
		}
		else {
			mp[x] = i;
			a.push_back(x);
		}
	}

	if (cycle.first == 0) {
		cout << a.back() << endl;
	}
	else {
		ll L = cycle.first;
		ll R = cycle.second;
		ll len = R - L + 1;

		ll pos;

		if (k + 1 < L) {
			pos = k + 1;
		}
		else {
			pos = L + ((k + 1 - L) % len);
		}
		cout << a[pos];
	}
}

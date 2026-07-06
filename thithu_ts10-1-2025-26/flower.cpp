#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("flower.inp", "r")) {
		freopen("flower.inp", "r", stdin);
		freopen("flower.out", "w", stdout);
	}

	ll n, m;
	cin >> n >> m;

	vector<pair<ll, ll>>v;
	FOR(i, 1, n) {
		ll l, r;
		cin >> l >> r;
		v.push_back({ l,1 });
		v.push_back({ r + 1,-1 });
	}
	sort(v.begin(), v.end());
	FOR(i, 1, v.size() - 1)v[i].second += v[i - 1].second;
	while (m--) {
		ll x;
		cin >> x;
		auto it = upper_bound(v.begin(), v.end(), make_pair(x, (ll)1e12));
		if (it == v.begin())cout << 0 << "\n";
		else cout << (--it)->second << "\n";
	}
}

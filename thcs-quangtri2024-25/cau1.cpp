#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau1.inp", "r")) {
		freopen("cau1.inp", "r", stdin);
		freopen("cau1.out", "w", stdout);
	}

	ll n, m[5], d;
	cin >> n >> m[1] >> m[2] >> m[3] >> d;
	sort(m + 1, m + 4);
	pair<ll, ll>range[5];
	range[1].first = max(1LL, m[1] - d);
	range[1].second = min(n, m[1] + d);
	range[2].first = max(1LL, m[2] - d);
	range[2].second = min(n, m[2] + d);
	range[3].first = max(1LL, m[3] - d);
	range[3].second = min(n, m[3] + d);

	ll res = range[1].second - range[1].first + range[2].second - range[2].first + range[3].second - range[3].first + 3;

	res -= max(0LL, range[1].second - range[2].first +1);
	res -= max(0LL, range[2].second - range[3].first +1);
	cout << n-res;
}

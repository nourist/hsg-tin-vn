#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	freopen("dankien1.inp", "r", stdin);
	freopen("dankien1.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, x, res = 0;
	cin >> n >> x;
	for (ll i = 0, t; i < n; i++) {
		cin >> t;
		res += abs(t - x);
	}
	cout << res;
}

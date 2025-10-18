#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("SQ.INP", "r", stdin);
	freopen("SQ.OUT", "w", stdout);

	unsigned ll a, b, n, res = 0;
	cin >> a >> b >> n;

	a %= b;
	for (ll i = 1; i <= n; i++) {
		a *= 10;
		res += a / b;
		a %= b;
	}
	cout << res;
}

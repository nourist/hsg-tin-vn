#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "bai2"

void solve() {
	ll n, x, k;
	string s;
	cin >> n >> x >> k >> s;

	ll pos = x;
	ll cnt = 0;

	int cur = 0; // index lệnh (0-based)

	for (ll step = 1; step <= k; step++) {
		// thực hiện lệnh
		if (s[cur] == 'L') pos--;
		else pos++;

		// check về 0
		if (pos == 0) {
			cnt++;
			cur = 0; // reset về lệnh 1
		}
		else {
			cur++;
			if (cur == n) cur = 0;
		}
	}

	cout << cnt << ' ' << pos << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".ans", "w", stdout);
	}

	int t;
	cin >> t;
	while (t--)solve();
}
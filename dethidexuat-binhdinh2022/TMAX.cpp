#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, a[(int)1e5 + 5];

bool allNegative() {
	FOR(i, 1, n)if (a[i] >= 0)return 0;
	return 1;
}

void solve() {
	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	if (allNegative()) {
		cout << *max_element(a + 1, a + n + 1) << ' ' << *max_element(a + 1, a + n + 1) << endl;
		return;
	}

	int res1 = 0;
	FOR(i, 1, n)if (a[i] >= 0)res1 += a[i];

	int sum = 0, res2 = 0;
	FOR(i, 1, n) {
		sum += a[i];
		res2 = max(res2, sum);
		if (sum < 0)sum = 0;
	}

	cout << res1 << ' ' << res2 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("TMAX.inp", "r")) {
		freopen("TMAX.inp", "r", stdin);
		freopen("TMAX.out", "w", stdout);
	}

	int t;
	cin >> t;
	while (t--)solve();
}

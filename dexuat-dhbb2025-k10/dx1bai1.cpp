#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n;
int a[(int)1e5 + 5];

void solve() {
	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	ll sum1 = 0;
	FOR(i, 1, n)sum1 = __gcd(sum1, 1LL * a[i]);

	ll sum2 = *min_element(a + 1, a + n + 1);

	cout << (sum1 == sum2 ? "YES" : "NO") << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("dx1bai1.inp", "r")) {
		freopen("dx1bai1.inp", "r", stdin);
		freopen("dx1bai1.out", "w", stdout);
	}

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

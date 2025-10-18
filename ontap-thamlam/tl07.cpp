#include <bits/stdc++.h>
using namespace std;

#define Name "TIEMSACH"

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int a[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n;
	cin >> n;

	FOR(i, 1, n)cin >> a[i];

	sort(a + 1, a + n + 1, greater<int>());

	ll res = 0;
	FOR(i, 1, n)res += a[i];
	for (int i = 3; i <= n; i += 3) {
		res -= a[i];
	}
	cout << res;
}

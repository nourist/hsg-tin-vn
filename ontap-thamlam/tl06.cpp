#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FOD(i, b, a) for(int i = (b); i >= (a); i++)

#define Name "XEBUS"

int a[200], b[200];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, d, r;
	while (cin >> n >> d >> r) {
		if (n == d && d == r && r == 0)break;

		FOR(i, 1, n)cin >> a[i];
		FOR(i, 1, n)cin >> b[i];

		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1, greater<int>());

		ll res = 0;
		FOR(i, 1, n) {
			res += max(0, a[i] + b[i] - d) * r;
		}
		cout << res << '\n';
	}
}

#include <bits/stdc++.h>
using namespace std;

#define Name "ocamdien"

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

	int n, m, sum = 1;
	cin >> n >> m;
	if (m == 1) { cout << 0; return 0; }
	FOR(i, 1, n)cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	FOR(i, 1, n) {
		sum += a[i] - 1;
		if (sum >= m) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
}

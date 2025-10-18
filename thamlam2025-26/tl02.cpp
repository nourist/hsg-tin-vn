#include <bits/stdc++.h>
using namespace std;

#define Name "btvn"

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int a[200];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, s;
	cin >> n >> s;

	FOR(i, 1, n)cin >> a[i];

	sort(a + 1, a + n + 1);

	int res = 0;
	FOR(i, 1, n) {
		if (s >= a[i]) {
			s += a[i];
		}
		else {
			cout << i - 1;
			return 0;
		}
	}
	cout << n;
}

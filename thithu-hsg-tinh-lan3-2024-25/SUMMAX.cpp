#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)2e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("SUMMAX.inp", "r")) {
		freopen("SUMMAX.inp", "r", stdin);
		freopen("SUMMAX.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];

	ll res = 0, sum = 0;
	FOR(i, 1, n) {
		sum += a[i];
		res = min(res, sum);
		if (sum > 0)sum = 0;
	}
	res *= -2;
	FOR(i, 1, n) res += a[i];
	cout << res;
}

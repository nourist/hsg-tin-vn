#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)1e5 + 5], l[(int)1e5 + 5], r[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n + 1) cin >> a[i];
	FOR(i, 1, n + 1)l[i] = max(l[i - 1], a[i]);
	FOD(i, n + 1, 1)r[i] = max(r[i + 1], a[i]);
	ll res = 0;
	FOR(i, 1, n) {
		res += min(l[i], r[i + 1]);
	}
	cout << res;
}

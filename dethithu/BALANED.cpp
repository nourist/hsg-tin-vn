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

	if (fopen("BALANED.inp", "r")) {
		freopen("BALANED.inp", "r", stdin);
		freopen("BALANED.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	sort(a + 1, a + n + 1);

	int l = 1, r = 1, res = 1;
	while (r <= n) {
		while (a[r] - a[l] > 5)l++;
		res = max(res, r - l + 1);
		r++;
	}
	cout << res;
}

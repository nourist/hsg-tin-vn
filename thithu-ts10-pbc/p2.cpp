#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int a[(int)5e4 + 4], f[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("p2.inp", "r")) {
		freopen("p2.inp", "r", stdin);
		freopen("p2.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		a[i] = (a[i - 1] + a[i]) % 7;
	}
	FOR(i, 1, 6)f[i] = 1e9;
	int res = 0;
	FOR(i, 1, n) {
		f[a[i]] = min(f[a[i]], i);
		res = max(res, i - f[a[i]]);
	}
	cout << res;
}

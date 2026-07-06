#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("PROMAX.inp", "r")) {
		freopen("PROMAX.inp", "r", stdin);
		freopen("PROMAX.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	cout << max(a[1] * a[2] * a[3], a[n] * a[n - 1] * a[1]);
}

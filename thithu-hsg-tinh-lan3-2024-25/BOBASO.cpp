#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)1e4 + 4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("BOBASO.inp", "r")) {
		freopen("BOBASO.inp", "r", stdin);
		freopen("BOBASO.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	sort(a + 1, a + n + 1);

	int res = 0;
	FOR(k, 3, n) {
		int i = 1, j = k - 1;
		while (i < j) {
			if (a[i] + a[j] == a[k]) {
				++res;
				++i;
				--j;
			}
			else if (a[i] + a[j] < a[k]) ++i;
			else --j;
		}
	}
	cout << res;
}

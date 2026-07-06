#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)3e5 + 5];
int l[(int)3e5 + 5];
int r[(int)3e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("COUNT.inp", "r")) {
		freopen("COUNT.inp", "r", stdin);
		freopen("COUNT.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	FOR(i, 1, n)cin >> a[i];

	ll res = 0;

	//case 1
	{
		int cnt = 0;
		FOR(i, 1, n) {
			if (a[i] % k == 0) {
				res += 1LL * cnt * (cnt + 1) / 2;
				cnt = 0;
			}
			else {
				cnt++;
			}
		}
		res += 1LL * cnt * (cnt + 1) / 2;
	}

	//case 2
	{
		FOR(i, 1, n) {
			if (a[i] % k == 0)l[i] = 0;
			else l[i] = l[i - 1] + 1;
		}
		FOD(i, n, 1) {
			if (a[i] % k == 0)r[i] = 0;
			else r[i] = r[i + 1] + 1;
		}

		FOR(i, 1, n) {
			if (a[i] % k == 0) {
				res += 1LL * (l[i - 1] + 1) * (r[i + 1] + 1);
			}
		}
	}

	cout << res;
}

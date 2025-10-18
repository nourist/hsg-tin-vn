#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int k;
int f[(int)5e5 + 10][28];
int d[28], dl[28], dr[28], s[28], sl[28], sr[28];
string str;

bool ok(int x) {
	FOR(i, x, str.size()) {
		FOR(j, 1, 26) {
			d[j] = f[i][j] - f[i - x][j];
			s[j] = d[j] * j;

			dl[j] = dl[j - 1] + d[j];
			sl[j] = sl[j - 1] + s[j];
		}
		FOD(j, 26, 1) {
			dr[j] = dr[j + 1] + d[j];
			sr[j] = sr[j + 1] + s[j];
		}

		int mn = 1e9;
		FOR(i, 1, 26) {
			mn = min(mn, dl[i - 1] * i - sl[i - 1] + sr[i + 1] - dr[i + 1] * i);
		}
		if (mn <= k) return true;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("PLAN.inp", "r")) {
		freopen("PLAN.inp", "r", stdin);
		freopen("PLAN.out", "w", stdout);
	}

	cin >> k >> str;

	FOR(i, 1, str.size()) {
		FOR(j, 1, 26) {
			f[i][j] = f[i - 1][j];
		}
		f[i][str[i - 1] - 'a' + 1]++;
	}

	int l = 1, r = str.size(), res = 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (ok(mid)) {
			res = max(res, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << res;
}

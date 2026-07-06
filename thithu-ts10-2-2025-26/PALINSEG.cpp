#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int f[(int)1e5 + 5][27];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("PALINSEG.inp", "r")) {
		freopen("PALINSEG.inp", "r", stdin);
		freopen("PALINSEG.out", "w", stdout);
	}

	string str;
	cin >> str;

	FOR(i, 1, str.size()) {
		FOR(c, 0, 25) {
			f[i][c] = f[i - 1][c];
		}
		f[i][str[i - 1] - 'a']++;
	}

	int q, l, r;
	cin >> q;

	while (q--) {
		cin >> l >> r;
		int cnt = 0;
		FOR(i, 0, 25) {
			cnt += (f[r][i] - f[l - 1][i]) % 2;
		}
		cout << (cnt <= 1 ? "YES\n" : "NO\n");
	}
}

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

	if(fopen("TSTR.inp", "r")) {
		freopen("TSTR.inp", "r", stdin);
		freopen("TSTR.out", "w", stdout);
	}

	string str;
	cin >> str;
	FOR(i, 1, str.size()) {
		for (int j = 0; j < 26; j++) {
			f[i][j] = f[i - 1][j];
		}
		f[i][str[i - 1] - 'a']++;
	}

	int q,a,b,c,d;
	cin >> q;
	while (q--) {
		cin >> a >> b >> c >> d;
		bool ok = 1;
		for (int i = 0; i < 26; i++) {
			int cnt1 = f[b][i] - f[a - 1][i];
			int cnt2 = f[d][i] - f[c - 1][i];
			ok = ok&&(cnt1 == cnt2);
		}
		cout<< (ok ? "YES" : "NO") << '\n';
	}
}

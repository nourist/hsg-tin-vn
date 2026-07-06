#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

bool d[(int)1e4 + 4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("vacation.inp", "r")) {
		freopen("vacation.inp", "r", stdin);
		freopen("vacation.out", "w", stdout);
	}

	int n, m;
	string str;
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> str;
		FOR(j, 0, m - 1) {
			if (str[j] == 'x') d[j + 1] = true;
		}
	}
	int cnt = 0, res = 0;
	FOR(i, 1, m) {
		if (!d[i]) {
			cnt++;
			res = max(res, cnt);
		}
		else {
			cnt = 0;
		}
	}
	cout << res << "\n";
}

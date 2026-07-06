#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define X first 
#define Y second 

pair<string, int> s[3333];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("MESS.inp", "r")) {
		freopen("MESS.inp", "r", stdin);
		freopen("MESS.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;
	FOR(i, 1, n)cin >> s[i].X, s[i].Y = i;

	sort(s + 1, s + n + 1);

	string w;
	int k;

	while (m--) {
		cin >> k >> w;
		int be = lower_bound(s + 1, s + n + 1, make_pair(w, 0)) - s;
		int en = upper_bound(s + 1, s + n + 1, make_pair(w + "}", 0)) - s;

		if (be + k - 1 >= en)cout << -1 << '\n';
		else cout << s[be + k - 1].Y << '\n';
	}
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

bool ok(string s, string t) {
	if (s.size() != t.size()) return false;
	int cnt = 0;
	FOR(i, 0, s.size() - 1) {
		if (s[i] != t[i]) cnt++;
	}
	return cnt <= 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("b2.inp", "r")) {
		freopen("b2.inp", "r", stdin);
		freopen("b2.out", "w", stdout);
	}

	string t, s;
	int n;

	cin >> t >> n;

	while (n--) {
		cin >> s;
		cout << (ok(t, s) ? "YES" : "NO") << '\n';
	}
}

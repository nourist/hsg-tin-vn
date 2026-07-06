#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

bool palin(string s) {
	string r = s;
	reverse(r.begin(), r.end());
	return s == r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("REPALIND.inp", "r")) {
		freopen("REPALIND.inp", "r", stdin);
		freopen("REPALIND.out", "w", stdout);
	}

	int t, k;
	string str;
	cin >> t;
	while (t--) {
		cin >> str >> k;
		if (palin(str)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}

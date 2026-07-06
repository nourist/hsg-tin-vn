#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("b4.inp", "r")) {
		freopen("b4.inp", "r", stdin);
		freopen("b4.out", "w", stdout);
	}

	int t, d[10];
	string str;

	cin >> t;
	while (t--) {
		cin >> str;
		memset(d, 0, sizeof(d));
		for (char c : str) d[c - '0']++;
		if (d[1] == str.size() || d[2] == str.size() || d[3] == str.size()) {
			cout << str.size() << "\n";
			continue;
		}
		if (d[1] % 2 == d[2] % 2 && d[2] % 2 == d[3] % 2) {
			cout << 2 << "\n";
		}
		else {
			cout << 1 << "\n";
		}
	}
}

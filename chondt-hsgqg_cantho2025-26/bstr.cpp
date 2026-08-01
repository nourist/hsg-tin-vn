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

	if (fopen("bstr.inp", "r")) {
		freopen("bstr.inp", "r", stdin);
		freopen("bstr.out", "w", stdout);
	}

	int n;
	string s, t;

	cin >> n >> s >> t;

	vector<int> x, y;

	FOR(i, 0, n - 1) {
		if (s[i] != t[i]) {
			if (s[i] == '0') {
				x.push_back(i + 1);
			}
			else {
				y.push_back(i + 1);
			}
		}
	}
	if ((x.size() + y.size()) % 2 == 1) {
		cout << -1;
		return 0;
	}

	if (x.size() % 2 == 0) {
		cout << x.size() / 2 + y.size() / 2 << endl;
		for (int i = 0; i < x.size(); i += 2) {
			cout << x[i] << ' ' << x[i + 1] << endl;
		}
		for (int i = 0; i < y.size(); i += 2) {
			cout << y[i] << ' ' << y[i + 1] << endl;
		}
	}
	else {
		cout << x.size() / 2 + y.size() / 2 + 2 << endl;
		for (int i = 0; i < x.size() - 1; i += 2) {
			cout << x[i] << ' ' << x[i + 1] << endl;
		}
		for (int i = 0; i < y.size() - 1; i += 2) {
			cout << y[i] << ' ' << y[i + 1] << endl;
		}
		int i = x.back();
		int j = y.back();

		cout << i << ' ' << i << endl << i << ' ' << j << endl;
	}
}

/*
i: 10
j: 01
*/
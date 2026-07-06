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

	vector<int>a;

	FOR(i, 0, n - 1) {
		if (s[i] != t[i]) {
			a.push_back(i + 1);
		}
	}

	if (a.size() % 2 == 1) {
		cout << -1;
		return 0;
	}

	cout << a.size() / 2 << endl;
	for (int i = 0; i < a.size(); i += 2) {
		cout << a[i + 1] << ' ' << a[i + 1] << endl << a[i + 1] << ' ' << a[i] << endl;
	}
}

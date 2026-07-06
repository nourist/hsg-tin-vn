#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int d1[(int)1e6 + 6], d2[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	int n;
	string s, t;
	cin >> n;
	cin.ignore();
	getline(cin, s);
	getline(cin, t);

	stringstream ss(s), tt(t);
	int x;
	while (ss >> x) d1[x]++;
	while (tt >> x) d2[x]++;
	FOR(i, 1, 1e6) {
		if (d1[i] >= 1 && d2[i] >= 1) {
			cout << i << ' ';
		}
	}
}

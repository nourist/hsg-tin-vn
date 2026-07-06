#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)2e6 + 6];
int f[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("Sorting.inp", "r")) {
		freopen("Sorting.inp", "r", stdin);
		freopen("Sorting.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	FOR(i, 1, n)f[a[i]]++;

	vector<int>odd, even;

	for (int i = 1; i <= 1e6; i += 2) {
		FOR(j, 1, f[i]) {
			odd.push_back(i);
		}
	}
	for (int i = 2; i <= 1e6; i += 2) {
		FOR(j, 1, f[i]) {
			even.push_back(i);
		}
	}

	FOR(i, 0, (int)min(odd.size(), even.size()) - 1) {
		cout << even[i] << ' ' << odd[i] << ' ';
	}

	FOR(i, (int)min(odd.size(), even.size()), (int)even.size() - 1) {
		cout << even[i] << ' ';
	}
	FOR(i, (int)min(odd.size(), even.size()), (int)odd.size() - 1) {
		cout << odd[i] << ' ';
	}
}

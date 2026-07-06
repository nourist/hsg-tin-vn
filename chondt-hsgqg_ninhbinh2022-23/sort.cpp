#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "sort"

int n, a[(int)1e5 + 5], b[(int)1e5 + 5], l[(int)1e5 + 5], r[(int)1e5 + 5];

void solve() {
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)cin >> b[i];

	memset(l, 0, sizeof l);
	memset(r, 0, sizeof r);

	FOR(i, 1, n)r[b[i]]++;

	FOR(i, 1, n) {
		r[b[i]]--;
		if (i != 1)l[b[i - 1]]++;

		if (a[i] == b[i])continue;
		if (a[i] > b[i]) {
			if (r[a[i]] == 0) {
				cout << "NO" << endl;
				return;
			}
			else {
				r[a[i]]--;
			}
		}
		if (a[i] < b[i]) {
			if (l[a[i]] == 0) {
				cout << "NO" << endl;
				return;
			}
			else {
				l[a[i]]--;
			}
		}
	}

	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int t;
	cin >> t;
	while (t--) { solve(); }
}
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define endl '\n'

int n, q;
int h[(int)2e5 + 5];
int f[(int)2e5 + 5];
int id[(int)2e5 + 5];

void compressPath() {
	id[1] = 1;
	FOR(i, 2, n) {
		if (h[i] == h[i - 1])id[i] = id[i - 1];
		else id[i] = id[i - 1] + 1;
	}
	FOR(i, 2, n) {
		h[id[i]] = h[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("CLIMBING.inp", "r")) {
		freopen("CLIMBING.inp", "r", stdin);
		freopen("CLIMBING.out", "w", stdout);
	}

	cin >> n >> q;
	FOR(i, 1, n)cin >> h[i];

	compressPath();
	n = id[n];

	if (h[1] < h[2])f[1] = 1;
	if (h[n] < h[n - 1])f[n] = 1;

	// FOR(i, 2, n - 1)if (h[i] < h[i - 1] && h[i] < h[i + 1])f[i] = 1;

	FOR(i, 2, n - 1) {
		if ((h[i] > h[i - 1] && h[i] > h[i + 1]) || (h[i] < h[i - 1] && h[i] < h[i + 1])) {
			f[i] = 1;
		}
	}

	FOR(i, 1, n)f[i] += f[i - 1];

	FOR(i, 1, q) {
		int l, r;
		cin >> l >> r;
		cout << max(1, f[id[r]] - f[id[l] + 1]) << endl;
	}
}

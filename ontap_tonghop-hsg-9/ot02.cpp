#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e5 + 8], d[(int)1e5 + 8], f[(int)1e5 + 8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("querytwo.INP", "r", stdin);
	freopen("querytwo.OUT", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d[a[i]]++;
	}
	for (int i = 1; i <= 1e5; i++) {
		if (d[i] > 0) {
			f[i] = i;
		}
		else {
			f[i] = f[i - 1];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (f[t] == 0)cout << -1 << endl;
		else cout << f[t] << endl;
	}
}

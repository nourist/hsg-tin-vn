#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int t, n, a[(int)1e5 + 5];
bool f[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	cin >> t;
	f[0] = 1;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			f[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			if (a[i] < i) {
				f[i] = f[i]||f[i - a[i] - 1];
			}
			if (a[i] + i <= 1e5) {
				f[i + a[i]] = f[i + a[i]] || f[i - 1];
			}
		}
		cout << (f[n] ? "YES" : "NO") << endl;
	}
}

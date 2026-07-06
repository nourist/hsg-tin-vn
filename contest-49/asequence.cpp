#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, a[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("asequence.inp", "r")) {
		freopen("asequence.inp", "r", stdin);
		freopen("asequence.out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 2; i <= n - 1; i++) {
		if (a[i] - a[i - 1] != a[i + 1] - a[i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}

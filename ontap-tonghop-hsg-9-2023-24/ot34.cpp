#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define name "STRING"

int x[CHAR_MAX], y[CHAR_MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);

	int n, m, res = 0;
	string a, b;

	cin >> n >> m >> a >> b;
	for (int i = 0; i < n; i++)x[a[i]]++;
	for (int i = 0; i < n - 1; i++)y[b[i]]++;
	for (int i = n - 1; i < m; i++) {
		y[b[i]]++;
		if (i - n >= 0) {
			y[b[i - n]]--;
		}
		int ok = 1;
		for (int i = 0; i < CHAR_MAX; i++) {
			if (x[i] != y[i]) {
				ok = 0;
				break;
			}
		}
		res += ok;
	}
	cout << res;
}

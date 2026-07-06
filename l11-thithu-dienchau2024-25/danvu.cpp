#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define name "danvu"

int a[(int)1e5 + 10], b[(int)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if (fopen(name".inp", "r")) {
		freopen(name".INP", "r", stdin);
		freopen(name".OUT", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	int j = 0, res = 0;
	for (int i = 0; i < n && j<m; i++) {
		if (a[i] > b[j]) {
			res++;
			j++;
		}
	}
	cout << res;
}

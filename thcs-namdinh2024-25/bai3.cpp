#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

pair<int, int>a[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int c, n;
	cin >> c >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (c >= a[i].first) {
			c += a[i].second;
		}
	}
	cout << c;
}

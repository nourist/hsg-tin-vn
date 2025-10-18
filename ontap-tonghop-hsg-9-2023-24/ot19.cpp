#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define name "chieusang"

const ll limit = 1e6 + 8;
int d[limit];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		d[x]++;
		d[y + 1]--;
	}
	int bst = 0;
	for (int i = 1; i <= 1e6; i++) {
		d[i] += d[i - 1];
		bst = max(bst, (int)d[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= 1e6; i++) {
		cnt += (d[i] == bst);
	}
	cout << bst << ' ' << cnt;
}

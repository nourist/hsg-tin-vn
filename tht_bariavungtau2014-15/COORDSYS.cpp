#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("COORDSYS.inp", "r")) {
		freopen("COORDSYS.inp", "r", stdin);
		freopen("COORDSYS.out", "w", stdout);
	}

	int n, x, mi = 1e9, ma = -1e9;
	cin >> n;
	while (n--) {
		cin >> x;
		mi = min(mi, x);
		ma = max(ma, x);
	}
	cout << ma - mi;
}

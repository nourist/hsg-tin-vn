#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	int t, a, b, mi = 2e9, mx=0;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		mi = min(mi, a + b);
		mx = max(mx, a + b);
	}
	cout << mx - mi;
}

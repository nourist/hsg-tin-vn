#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	ll n, k, x, s = 0;
	cin >> n>>k;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (i<=k)s += x;
	}
	cout << s;
}

#include <bits/stdc++.h>
using namespace std;

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

	ll n, x, res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x % 10 > x / 10 % 10)res += x;
	}
	cout << res;
}

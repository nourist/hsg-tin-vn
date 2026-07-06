#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau1.inp", "r")) {
		freopen("cau1.inp", "r", stdin);
		freopen("cau1.out", "w", stdout);
	}

	ll res = 1, a, b, c;
	cin >> a >> b >> c;
	for (a; a <= b; a++) {
		res *= a;
		res %= c;
	}
	cout << res;
}

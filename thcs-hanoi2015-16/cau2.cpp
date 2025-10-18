#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	ll n, x, res = 0;
	cin >> n;
	while (n--) {
		cin >> x;
		res = max(res, x);
		cout << res << ' ';
	}
}

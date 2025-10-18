#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool d[(int)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	ll n;
	cin >> n;
	ll cnt = 1, res = 1;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		d[i] = t < 0;
	}
	for (int i = 2; i <= n; i++) {
		if (d[i] == d[i - 1]) {
			cnt++;
			res = max(res, cnt);
		}
		else {
			cnt = 1;
		}
	}
	cout << res;
}

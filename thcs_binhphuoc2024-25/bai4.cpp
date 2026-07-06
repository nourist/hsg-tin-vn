#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e5 + 10];

bool ok(ll n) {
	while (n != 0) {
		if (n % 10 % 2 == 0) return false;
		n /= 10;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	ll cnt = 0, res = 0;
	for (int i = 0; i < n; i++) {
		if (ok(a[i])) {
			cnt++;
			res = max(res, cnt);
		}
		else {
			cnt = 0;
		}
	}
	cout << res;
}

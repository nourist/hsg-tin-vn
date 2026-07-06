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

	if (fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	ll k, x;
	cin >> k >> x;

	ll num = 0;
	string s = "";
	int ch = x + '0';
	FOR(i, 1, 1e5) {
		num = (num * 10 + x) % k;
		s += ch;
		if (num % k == 0) {
			cout << s;
			return 0;
		}
	}
	cout << -1;
}

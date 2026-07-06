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

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.ans", "w", stdout);
	}

	ll x, k;
	cin >> x >> k;

	while (x != 0 && k != 0) {
		if (x % 2 == 0) {
			string a = to_string(x);
			string b = to_string(x);

			sort(a.begin(), a.end());
			sort(b.begin(), b.end(), greater<int>());

			x = stoll(b) - stoll(a);
		}
		else {
			string a = to_string(x);
			sort(a.begin(), a.end());
			x = x - stoll(a);
		}

		k--;
	}
	cout << x;
}

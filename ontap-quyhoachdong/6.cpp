#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define name ""

ll fb[100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen(name".inp", "r", stdin);
	// freopen(name".out", "w", stdout);

	ll x;
	cin >> x;
	fb[1] = fb[2] = 1;
	ll i = 3;
	for (i; i <= 70; i++) {
		fb[i] = fb[i - 1] + fb[i - 2];
		if (fb[i] > x)break;
	}
	i--;
	int res = 0;
	for (i; i >= 1; i--) {
		if (fb[i] <= x) {
			x -= fb[i];
			res++;
		}
	}
	cout << res;
}

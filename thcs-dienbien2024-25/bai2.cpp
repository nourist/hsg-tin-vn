#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll l, r;
	cin >> l >> r;

	int res = 0;
	for (int i = l; i <= r; i++) {
		for (int j = i + 1; j <= r; j++) {
			if (__gcd(i, j) == 1)res++;
		}
	}
	cout << res;
}

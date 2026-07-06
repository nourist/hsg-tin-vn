#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	pair<ll, ll>a, b;
	cin >> a.first >> b.first >> a.second >> b.second;
	if (a.first > b.first) {
		auto t = a;
		a = b;
		b = t;
	}

	if (b.first <= 9 && a.first <= 9) {
		ll resa = b.second / b.first;
		ll resb = 0;
		cout << resa << ' ' << resb;
	}
	else if (b.first <= 9) {
		ll resa = b.second / b.first;
		ll resb = (a.second - 9 * resa) / (a.first - 9);
		cout << resa << ' ' << resb;
	}
	else {
		ll resb = (a.second - b.second) / (a.first - b.first);
		ll resa = (a.second - (a.first - 9) * resb) / 9;
		cout << resa << ' ' << resb;
	}
}

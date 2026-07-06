#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll page[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	ll n;
	cin >> n;

	page[1] = 6;
	for (int i = 2; i <= 10; i++) {
		page[i] =  (pow(10, i) - pow(10, i - 1));
	}

	ll res = 0;
	for (ll i = 1; i <= 6; i++) {
		if (n > page[i]*i) {
			res += page[i];
			n -= page[i]*i;
		}
		else {
			res += n / i;
			break;
		}
	}
	cout << res + 3;
}

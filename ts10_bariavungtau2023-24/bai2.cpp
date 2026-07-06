#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll to10(string str) {
	ll t = 1, s = 0;
	for (int i = str.size() - 1; i >= 0; i--) {
		s += t * (str[i] - '0');
		t *= 2;
	}
	return s;
}

// #define upsqrt(n) sqrt(n)==(ll)sqrt(n)?sqrt(n):(int)sqrt(n)+1

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	string a, b;
	cin >> a >> b;

	cout << max(0LL, (ll)sqrt(to10(b)) - (ll)ceil(sqrt(to10(a))) + 1LL);
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

string base5(ll n) {
	if (n == 0) return "0";

	string result = "";
	while (n > 0) {
		ll remainder = (n - 1) % 5; 
		result = to_string(remainder + 1) + result; 
		n = (n - 1) / 5; 
	}
	return result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau4.inp", "r")) {
		freopen("cau4.inp", "r", stdin);
		freopen("cau4.out", "w", stdout);
	}

	ll n;
	cin >> n;

	for (char ch : base5(n)) {
		cout << (char)((ch - '0') * 2 - 1 + '0');
	}
}

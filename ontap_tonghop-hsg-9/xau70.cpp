#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll solve(ll a, ll b) {
	if (b == 0)return 1;
	else {
		ll p = solve(a, b / 2);
		if (b % 2 == 0)return p * p % ((int)1e9 + 7);
		else return p * p % ((int)1e9 + 7) * a % ((int)1e9 + 7);
	}
}

const int mod = (int)1e9 + 7;

ll chiadu(string str) {
	ll res = 0;
	for (int i = 0; i < str.size(); i++) {
		res *= 10;
		res %= mod;
		res += str[i] - '0';
		res %= mod;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("LuyThuaLon.INP", "r", stdin);
	freopen("LuyThuaLon.OUT", "w", stdout);

	string str;

	ll a, b;
	cin >> str >> b;
	a = chiadu(str);
	cout << solve(a, b);
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	ll n;
	string s;
	cin >> n;
	ll res = 0;
	while (n--) {
		cin >> s;
		res += s.back() == '9';
	}
	cout << res;
}

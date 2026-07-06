#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll f[300];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("LUCKY.inp", "r")) {
		freopen("LUCKY.inp", "r", stdin);
		freopen("LUCKY.out", "w", stdout);
	}

	string str;
	cin >> str;

	ll res = 0, s = 0, pow = 1;

	f[0] = 1;
	FOD(i, str.size() - 1, 0) {
		s = (s + (str[i] - '0') * pow) % 291;
		pow = pow * 10 % 291;
		res += f[s]++;
	}
	cout << res;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("tuvung.inp", "r")) {
		freopen("tuvung.inp", "r", stdin);
		freopen("tuvung.out", "w", stdout);
	}

	string str;
	cin >> str;
	ll res = 0, cnta = 0, cntb = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'u' || str[i] == 'o') {
			res += cntb;
			cnta++;
		}
		else {
			res += cnta;
			cntb++;
		}
	}
	cout << res;
}

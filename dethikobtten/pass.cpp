#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll x[10], d[255];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("pass.inp", "r")) {
		freopen("pass.inp", "r", stdin);
		freopen("pass.out", "w", stdout);
	}


	string str;
	cin >> str;

	FOR(i, 1, 4)cin >> x[i];
	for (auto i : str)d[i] = 1;
	string res = "";
	FOR(i, 'a', 'z')if (!d[i])res += i;
	FOR(i, 1, 4)cout << res[x[i] - 1];
}

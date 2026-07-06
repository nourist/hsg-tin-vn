#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[102];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai14_game.inp", "r")) {
		freopen("bai14_game.inp", "r", stdin);
		freopen("bai14_game.out", "w", stdout);
	}

	int n;
	cin >> n;

	FOR(i, 1, n)cin >> a[i];
	int res = abs(a[2] - a[1]);
	FOR(i, 3, n) {
		res = __gcd(res, abs(a[i] - a[i - 1]));
	}
	vector<int>f;
	cout << res<<' ';
	for (int i = 2; i * i <= res; i++) {
		if (res % i == 0) {
			cout << i << ' ';
			if (i * i != res)f.push_back(i);
		}
	}
	FOD(i, f.size() - 1, 0)cout << f[i] << ' ';
}

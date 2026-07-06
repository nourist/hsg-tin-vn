#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("DUONGTRON.inp", "r")) {
		freopen("DUONGTRON.inp", "r", stdin);
		freopen("DUONGTRON.out", "w", stdout);
	}

	unordered_map<int, int>mp;

	int n, x, y;
	cin >> n;
	FOR(i, 1, n) {
		cin >> x >> y;
		mp[x * x + y * y]++;
	}

	int res = 0;
	for (auto i : mp) res = max(res, i.second);
	cout << res;
}

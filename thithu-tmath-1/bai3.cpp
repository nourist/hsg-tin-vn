#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	unordered_map<int, int>mp;

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	int res = 1e9;
	FOR(i, 1, n) {
		if (mp.find(a[i]) != mp.end()) {
			res = min(res, i - mp[a[i]]);
		}
		mp[a[i]] = i;
	}
	cout << (res == 1e9 ? -1 : res) << endl;
}

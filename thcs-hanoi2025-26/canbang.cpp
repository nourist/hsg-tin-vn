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

	if (fopen("canbang.inp", "r")) {
		freopen("canbang.inp", "r", stdin);
		freopen("canbang.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;
	FOR(i, 1, n)cin >> a[i];

	unordered_map<int, bool>mp;
	FOR(i, 1, n)mp[a[i]] = 1;

	int res = 0;
	FOR(i, 1, n) {
		res += mp[a[i] - k] && mp[a[i] + k];
	}
	cout << res;
}

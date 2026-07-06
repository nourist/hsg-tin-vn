#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

string a[(int)2e4 + 4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("BAOMAT.inp", "r")) {
		freopen("BAOMAT.inp", "r", stdin);
		freopen("BAOMAT.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	sort(a + 1, a + n + 1, [&](string x, string y) {
		return x.size() < y.size();
		});

	int res = 0;

	unordered_map<string, int>mp;

	FOR(i, 1, n) {
		unordered_map<string, bool>used;

		FOR(l, 1, a[i].size())FOR(j, 0, a[i].size() - l) {
			string t = a[i].substr(j, l);
			if (used[t])continue;

			used[t] = 1;

			res += mp[t];
		}

		res += mp[a[i]];

		mp[a[i]]++;
	}

	cout << res;
}

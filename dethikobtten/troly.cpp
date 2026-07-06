#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)5e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("troly.inp", "r")) {
		freopen("troly.inp", "r", stdin);
		freopen("troly.out", "w", stdout);
	}

	int n, q, x;
	cin >> n >> q;

	FOR(i, 1, n)cin >> a[i];
	unordered_map<int, int>last_appear, res;
	FOR(i, 1, n) {
		if (last_appear[a[i]]) {
			if (res.find(a[i]) == res.end())res[a[i]] = i - last_appear[a[i]];
			else res[a[i]] = min(res[a[i]], i - last_appear[a[i]]);
		}
		last_appear[a[i]] = i;
	}
	FOR(i, 1, q) {
		cin >> x;
		cout << res[x] << '\n';
	}
}

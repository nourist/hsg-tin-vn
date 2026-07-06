#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, k;
string s;
int a[(int)4e5 + 5];

bool ok(int mid) {
	vector<int>cnt;

	FOR(i, 1, n) {
		if (a[i] <= mid)continue;

		if (cnt.empty() || cnt.back() != s[i - 1]) {
			cnt.push_back(s[i - 1]);
		}
	}

	if (cnt.size() % 2 == 1)return (cnt.size() + 1) / 2 <= k;
	else return (cnt.size() + 1) / 2 + 1 <= k;
}

void solve() {
	cin >> n >> k >> s;
	FOR(i, 1, n)cin >> a[i];

	int l = 0, r = 1e9, res = 1e9;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (ok(mid)) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("p3.inp", "r")) {
		freopen("p3.inp", "r", stdin);
		freopen("p3.out", "w", stdout);
	}

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int LIS(vector<int>& a) {
	vector<int>lis;
	for (auto x : a) {
		if (lis.empty() || lis.back() <= x) lis.push_back(x);
		else *lower_bound(lis.begin(), lis.end(), x) = x;
	}
	return lis.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("BEADS.inp", "r")) {
		freopen("BEADS.inp", "r", stdin);
		freopen("BEADS.out", "w", stdout);
	}

	int n;
	vector<int>a;
	cin >> n;
	FOR(i, 1, n) {
		int x; cin >> x;
		a.push_back(x);
	}
	int res = LIS(a);
	reverse(a.begin(), a.end());
	res = max(res, LIS(a));
	cout << res;
}

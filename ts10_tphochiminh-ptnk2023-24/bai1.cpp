#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, m, a[100005], b[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	if (fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = -1e9;

	cin >> m;
	for (int i = 1; i <= m; i++) cin >> b[i];
	b[m + 1] = 1e9;

	vector<int> l, r;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= a[i - 1]) l.push_back(a[i]);
		else break;
	}

	for (int i = m; i >= 1; i--) {
		if (b[i] <= b[i + 1]) r.push_back(b[i]);
		else break;
	}
	reverse(r.begin(), r.end());

	int res = 0;
	for (int i = 0; i < l.size(); i++) {
		int j = lower_bound(r.begin(), r.end(), l[i]) - r.begin();
		res = max(res, i + 1 + (int)r.size() - j);
	}
	cout << res;
}

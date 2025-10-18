#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define name "dpwavio"

int a[1008];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int res = 0;
	vector<int>d, l(n + 1), r(n + 1);

	for (int i = 1; i <= n; i++) {
		if (d.empty() || d.back() < a[i])d.push_back(a[i]);
		else *lower_bound(d.begin(), d.end(), a[i]) = a[i];
		l[i] = d.size();
	}

	d.clear();
	for (int i = n; i >= 1; i--) {
		if (d.empty() || d.back() < a[i])d.push_back(a[i]);
		else *lower_bound(d.begin(), d.end(), a[i]) = a[i];
		r[i] = d.size();
	}

	for (int i = 1; i <= n; i++) {
		res = max(res, min(r[i], l[i]) * 2 - 1);
	}
	cout << res;
}

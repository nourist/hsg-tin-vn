#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int x[(int)1e5 + 10], p[(int)1e5 + 10], d[(int)1e5 + 10], pp[(int)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	int n, m, q, k;
	cin >> n >> m >> q >> k;

	for (int i = 1; i <= m; i++)cin >> x[i];
	for (int i = 1; i <= q; i++)cin >> p[i], pp[i] = p[i];

	sort(p + 1, p + q + 1);

	for (int i = 1; i <= m; i++) {
		d[lower_bound(p + 1, p + q + 1, x[i] - k) - p]++;
		d[upper_bound(p + 1, p + q + 1, x[i] + k) - p]--;
	}

	for (int i = 1; i <= 1e5; i++) {
		d[i] += d[i - 1];
	}

	unordered_map<int, int>mp;
	for (int i = 1; i <= q; i++) {
		mp[p[i]] = d[i] % 2;
	}

	for (int i = 1; i <= q; i++) {
		cout << (mp[pp[i]] ? "D" : "V") << '\n';
	}
}

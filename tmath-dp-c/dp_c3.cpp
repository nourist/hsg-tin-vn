#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e3 + 3], l[(int)1e3 + 3], r[(int)1e3 + 3], h[(int)1e3+3];

int solve(int n) {
	stack<int>s;
	for (int i = 0; i < n; i++) {
		if (s.empty() || a[s.top()] <= a[i]) {
			s.push(i);
		}
		else {
			while (!s.empty() && a[s.top()] > a[i]) {
				r[s.top()] = i - 1;
				s.pop();
			}
			s.push(i);
		}
	}
	while (!s.empty()) {
		r[s.top()] = n - 1;
		s.pop();
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s.empty() || a[s.top()] <= a[i]) {
			s.push(i);
		}
		else {
			while (!s.empty() && a[s.top()] > a[i]) {
				l[s.top()] = i + 1;
				s.pop();
			}
			s.push(i);
		}
	}
	while (!s.empty()) {
		l[s.top()] = 0;
		s.pop();
	}
	pair<int, pair<int, int>>res;
	for (int i = 0; i < n; i++) {
		res = max(res, { a[i] * (r[i] - l[i] + 1),{l[i],r[i]} });
	}
	// cout << res.first << ' ' << res.second.first + 1 << ' ' << res.second.second + 1;
	return res.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("dp_c3.inp", "r")) {
		freopen("dp_c3.inp", "r", stdin);
		freopen("dp_c3.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> h[j];
			if (h[j] == 0)a[j] = 0;
			else a[j]++;
		}
		res = max(res, solve(m));
	}
	cout << res;
}

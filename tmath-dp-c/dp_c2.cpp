#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e5 + 5], l[(int)1e5 + 5], r[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("dp_c2.inp", "r")) {
		freopen("dp_c2.inp", "r", stdin);
		freopen("dp_c2.out", "w", stdout);
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
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
		r[s.top()] = n-1;
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
		res = max(res, {a[i] * (r[i] - l[i] + 1),{l[i],r[i]}});
	}
	// cout << res.first << ' ' << res.second.first + 1 << ' ' << res.second.second + 1;
	cout << res.first;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e5 + 5];
int l[(int)1e5 + 5];
int r[(int)1e5 + 5];
pair<int, int> p[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("dp_c6.inp", "r")) {
		freopen("dp_c6.inp", "r", stdin);
		freopen("dp_c6.out", "w", stdout);
	}

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; i++)cin >> a[i];

	stack<int>s;
	for (int i = 0; i < n; i++) {
		if (s.empty() || a[s.top()] >= a[i])s.push(i);
		else {
			while (!s.empty() && a[s.top()] < a[i]) {
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
		if (s.empty() || a[s.top()] >= a[i])s.push(i);
		else {
			while (!s.empty() && a[s.top()] < a[i]) {
				l[s.top()] = i + 1;
				s.pop();
			}
			s.push(i);
		}
	}

	for (int i = 0; i < n; i++) {
		p[i] = { a[i], r[i] - l[i] + 1 };
	}
	sort(p, p + n);
	for (int i = 1; i < n; i++) {
		p[i] = { p[i].first, max(p[i - 1].second, p[i].second) };
	}
	while (q--) {
		int k;
		cin >> k;
		auto it = upper_bound(p, p + n, make_pair(k,(int)1e9));
		if (it == p)cout << 0;
		else cout << (--it)->second;
		cout << '\n';
	}
}
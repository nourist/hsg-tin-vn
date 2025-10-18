#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool d[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, n;
	cin >> m >> n;

	for (int t, i = 0; i < n; i++) {
		cin >> t; d[t] = 1;
	}
	vector<int>v;
	vector<pair<int, int>>p;
	for (int i = 1; i <= 1e6; i++) {
		if (d[i]) {
			v.push_back(i);
		}
		else if (!v.empty()) {
			p.push_back({ v.front(), v.back() });
			v.clear();
		}
	}
	if (!v.empty()) {
		p.push_back({ v.front(), v.back() });
		v.clear();
	}

	int res = max(p.front().second - p.front().first + 1 + (p.front().first != 1), p.back().second - p.back().first | 1 + (p.back().second != m));
	for (int i = 0; i < p.size() - 1; i++) {
		int s1 = p[i].second - p[i].first + 1;
		int s2 = p[i + 1].second - p[i + 1].first + 1;
		res = max(res, s1 + 1);
		if (p[i].second - p[i + 1].first == -2) {
			res = max(res, s1 + s2 + 1);
		}
	}
	cout << res;
}

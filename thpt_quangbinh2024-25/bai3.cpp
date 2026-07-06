#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, k, a[(int)2e5+5], b[(int)2e5+5];

vector<vector<int>>split() {
	vector<vector<int>> res;
	vector<int>tmp;
	for (int i = 1; i <= n; i++) {
		if (a[i - 1] % a[i] == 0) {
			tmp.push_back(i);
		}
		else {
			res.push_back(tmp);
			tmp = {i};
		}
	}
	if (tmp.size() > 0) {
		res.push_back(tmp);
	}
	return res;
}

int solve(vector<int> v) {
	int l = 0, r = 0;
	ll sum = 0;
	int res = 0;
	while (r < v.size()) {
		sum += b[v[r]];
		while (sum > k) {
			sum -= b[v[l++]];
		}
		res = max(res, r - l + 1);
		r++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	vector<vector<int>> v = split();

	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		res = max(res, solve(v[i]));
	}
	cout<<(res==1?0:res);
}

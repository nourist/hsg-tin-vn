#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)1e3 + 3][(int)1e3 + 3], f[(int)1e3 + 3][(int)1e3 + 3], l[(int)1e3 + 3], r[(int)1e3 + 3];

int solve(int arr[], int n) {
	stack<int> s;
	FOR(i, 1, n) {
		while (!s.empty() && arr[s.top()] >= arr[i])s.pop();
		if (s.empty())l[i] = 1;
		else l[i] = s.top() + 1;
		s.push(i);
	}
	while (!s.empty())s.pop();
	FOD(i, n, 1) {
		while (!s.empty() && arr[s.top()] >= arr[i])s.pop();
		if (s.empty())r[i] = n;
		else r[i] = s.top() - 1;
		s.push(i);
	}
	int res = 0;
	FOR(i, 1, n)res = max(res, arr[i] * (r[i] - l[i] + 1));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("rec.inp", "r")) {
		freopen("rec.inp", "r", stdin);
		freopen("rec.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;
	FOR(i, 1, n)FOR(j, 1, m)cin >> a[i][j];

	FOR(i, 1, n)FOR(j, 1, m)if (a[i][j] == 1)f[i][j] = f[i - 1][j] + 1;
	int res = 0;
	FOR(i, 1, n) {
		res = max(res, solve(f[i], m));
	}
	cout << res;
}

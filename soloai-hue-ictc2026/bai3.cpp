#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first 
#define Y second

int n, m, k;
int a[(int)1e5 + 5];

namespace sub1 {
	int f[(int)1e5 + 5];
	int cnt = 0;

	void add(int x) {
		if (f[x] == m)cnt++;
		f[x]++;
	}

	void rem(int x) {
		if (f[x] == m + 1)cnt--;
		f[x]--;
	}

	bool check() {
		return k == 0;
	}

	void solve() {
		int l = 1, r = 1;

		int res = 1;

		while (r <= n) {
			add(a[r]);

			if (cnt > 0) {
				res++;
				while (l != r) {
					rem(a[l++]);
				}
			}

			r++;
		}

		cout << res;
		exit(0);
	}
}

namespace fuck {
	int f[(int)1e5 + 5];
	int cnt = 0;

	void add(int x) {
		if (f[x] == m)cnt++;
		f[x]++;
	}

	void rem(int x) {
		if (f[x] == m + 1)cnt--;
		f[x]--;
	}

	bool check() {
		return k == 0;
	}

	void solve() {
		int l = 1, r = 1;

		int res = 1;

		while (r <= n) {
			add(a[r]);

			if (cnt > 0) {
				res++;
				while (l != r) {
					rem(a[l++]);
				}
				rem(a[l]);
				l++;
			}

			r++;
		}

		cout << res;
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	cin >> n >> m >> k;
	FOR(i, 1, n) cin >> a[i];

	if (sub1::check())sub1::solve();
	fuck::solve();
}

/*
gọi dp[i][j] là đoạn con kết thúc

*/
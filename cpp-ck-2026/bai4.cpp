#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n;
int a[5005];
int f[5005];

vector<int>pos[5005];

void compress() {
	map<int, int>mp;
	FOR(i, 1, n)mp[a[i]] = 1;

	int cnt = 1;
	for (auto it = mp.begin(); it != mp.end(); it++)it->second = cnt++;

	FOR(i, 1, n)a[i] = mp[a[i]];
}

int solve(int x) {
	FOR(i, 1, n)f[i] = f[i - 1] + (a[i] == x ? 0 : (a[i] < x ? -1 : 1));

	int lastL = 0;
	int res = 0;

	FOR(j, 1, pos[x].size() - 1) {
		int i = j - 1;

		int l = pos[x][i], r = pos[x][j];

		FOD(k, r - 1, l) {
			if (f[k] - f[lastL] == 0 && (k - lastL) % 2 == 1) {
				res++;
				lastL = k;
				break;
			}
		}
	}

	if (f[n] - f[lastL] == 0) {
		return res + 1;
	}
	else return 0;
}

namespace sub1 {
	vector<int>res;
	int resN = 0;

	int fx[100], fx1[200], hashx[100];

	bool ok(int l, int r) {
		if (l > r)return 1;
		if ((l + r) % 2 == 1)return 0;


		int mid = (l + r) / 2;

		if (mid >= fx1[r] - fx1[l - 1] && mid <= fx[r] - fx[l - 1])return 1;
		else return 0;
	}

	void Try(int i, int x) {
		if (i == pos[x].size() || res.back() == n) {
			// for (auto abc : res)cout << abc << ' ';
			// cout << endl;
			if (ok(res.back() + 1, n)) {
				resN = max(resN, (int)res.size() - 1);
			}
			return;
		}
		if (pos[x][i] <= res.back())return;
		FOR(k, pos[x][i], n) {
			if (hashx[k] - hashx[res.back()] >= 1 && ok(res.back() + 1, k)) {
				res.push_back(k);
				Try(i + 1, x);
				res.pop_back();
			}
		}
	}

	int solve(int x) {
		FOR(i, 1, n) {
			if (a[i] >= x)fx[i]++;
			if (a[i] >= x + 1)fx1[i]++;
			if (a[i] == x)hashx[i]++;
			fx[i] += fx[i - 1];
			fx1[i] += fx1[i - 1];
			hashx[i] += hashx[i - 1];
		}

		Try(0, x);
		return resN;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	compress();

	FOR(i, 1, n)pos[a[i]].push_back(i);

	sub1::res.push_back(0);

	int res = 0;
	FOR(i, 1, n) {
		if (n <= 15)res = max(res, sub1::solve(a[i]));
		res = max(res, solve(a[i]));
	}
	cout << res;
}

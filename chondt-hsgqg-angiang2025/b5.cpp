#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); i++)
#define FOD(i,r,l) for (int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "b5"

int n, m;
ll k, t, a[1500][1500], f[1500][1500];

ll sum(int x, int y, int u, int v) {
	if (x<1 || y<1 || u>n || v>m || u < x || v < y)return 1e18;
	return f[u][v] - f[u][y - 1] - f[x - 1][v] + f[x - 1][y - 1];
}

namespace sub12 {
	ll solveCell(int i, int j) {
		int l = 0, r = min(i, j), res = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (sum(i - mid + 1, j - mid + 1, i, j) <= t) {
				res = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		return res * res;
	}

	void solve() {
		ll res = 0;
		FOR(i, 1, n)FOR(j, 1, m)res = max(res, solveCell(i, j));
		cout << res;
	}
}

ll costTL(int i, int j, int l) {
	return sum(i - l + 1, j - l + 1, i, j);
}

ll costBR(int i, int j, int l) {
	return sum(i, j, i + l - 1, j + l - 1);
}

namespace sub34 {
	ll T[333][333], B[333][333], L[333][333], R[333][333];

	void solve() {
		FOR(i, 0, 321)FOR(l, 1, 321)T[i][l] = B[i][l] = L[i][l] = R[i][l] = 1e18;

		FOR(i, 1, n)FOR(l, 1, min(i, m)) {
			T[i][l] = T[i - 1][l];
			FOR(j, 1, m) {
				T[i][l] = min(T[i][l], costTL(i, j, l));
			}
		}
		FOD(i, n, 1)FOR(l, 1, min(n - i + 1, m)) {
			B[i][l] = B[i + 1][l];
			FOR(j, 1, m) {
				B[i][l] = min(B[i][l], costBR(i, j, l));
			}
		}
		FOR(i, 1, m)FOR(l, 1, min(i, n)) {
			L[i][l] = L[i - 1][l];
			FOR(j, 1, n) {
				L[i][l] = min(L[i][l], costTL(j, i, l));
			}
		}
		FOD(i, m, 1)FOR(l, 1, min(m - i + 1, n)) {
			R[i][l] = R[i + 1][l];
			FOR(j, 1, n) {
				R[i][l] = min(R[i][l], costBR(j, i, l));
			}
		}

		int res = 0;
		FOR(i, 1, n - 1) {
			int j = i + 1;
			FOR(l1, 0, 300)FOR(l2, 0, 300) {
				if (T[i][l1] + B[j][l2] <= t)res = max(res, l1 * l1 + l2 * l2);
			}
		}
		FOR(i, 1, m - 1) {
			int j = i + 1;
			FOR(l1, 1, 300)FOR(l2, 1, 300) {
				if (L[i][l1] + R[j][l2] <= t)res = max(res, l1 * l1 + l2 * l2);
			}
		}
		cout << res;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> m >> k >> t;
	FOR(i, 1, n)FOR(j, 1, m)cin >> a[i][j];
	FOR(i, 1, n)FOR(j, 1, m)f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];

	if (k == 1)sub12::solve();
	else sub34::solve();
}

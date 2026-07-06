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
#define Name "build"

int a[404][404];
int f[404][404][4];// 1 là nước, 2 là đất, 3 là đá 
int up[404][404];
int down[404][404];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	FOR(i, 1, n) {
		string s;
		cin >> s;
		FOR(j, 1, m) {
			if (s[j - 1] == 'x')a[i][j] = 1;
			else if (s[j - 1] == 'c')a[i][j] = 2;
			else a[i][j] = 3;
		}
	}

	FOR(i, 1, n) {
		FOR(j, 1, m) {
			FOR(k, 1, 3)
				f[i][j][k] = f[i][j - 1][k];
			f[i][j][a[i][j]]++;
		}
	}

	FOR(i, 1, n)FOR(j, 1, m) {
		if (a[i][j] == 3)up[i][j] = up[i - 1][j] + 1;
		else up[i][j] = 0;
	}

	FOD(i, n, 1)FOR(j, 1, m) {
		if (a[i][j] == 3)down[i][j] = down[i + 1][j] + 1;
		else down[i][j] = 0;
	}

	int res = 0;
	FOR(row, 1, n)FOR(i, 1, m)FOR(j, i + 2, m) {
		if (f[row][j][1] - f[row][i - 1][1] >= 1 || f[row][j][2] - f[row][i - 1][2] >= 2)continue;

		int top1 = row - up[row - 1][i];
		int bottom1 = row + down[row + 1][i];

		int top2 = row - up[row - 1][j];
		int bottom2 = row + down[row + 1][j];

		if (max(top1, top2) != row && min(bottom1, bottom2) != row) {
			res = max(res, j - i - 1 + (min(bottom1, bottom2) - max(top1, top2) + 1) * 2);
		}
		if (f[row][j][2] - f[row][i - 1][2] == 0) {
			if (a[top1 - 1][i] == 2) {
				int oldTop1 = top1;
				top1 -= up[top1 - 2][i] + 1;

				if (max(top1, top2) != row && min(bottom1, bottom2) != row) {
					res = max(res, j - i - 1 + (min(bottom1, bottom2) - max(top1, top2) + 1) * 2);
				}

				top1 = oldTop1;
			}
			if (a[top2 - 1][j] == 2) {
				int oldTop2 = top2;
				top2 -= up[top2 - 2][j] + 1;

				if (max(top1, top2) != row && min(bottom1, bottom2) != row) {
					res = max(res, j - i - 1 + (min(bottom1, bottom2) - max(top1, top2) + 1) * 2);
				}

				top2 = oldTop2;
			}
			if (a[bottom1 + 1][i] == 2) {
				int oldBottom1 = bottom1;
				bottom1 += up[bottom1 + 2][i] + 1;

				if (max(top1, top2) != row && min(bottom1, bottom2) != row) {
					res = max(res, j - i - 1 + (min(bottom1, bottom2) - max(top1, top2) + 1) * 2);
				}

				bottom1 = oldBottom1;
			}
			if (a[bottom2 + 1][j] == 2) {
				int oldBottom2 = bottom2;
				bottom2 += up[bottom2 + 2][j] + 1;

				if (max(top1, top2) != row && min(bottom1, bottom2) != row) {
					res = max(res, j - i - 1 + (min(bottom1, bottom2) - max(top1, top2) + 1) * 2);
				}

				bottom2 = oldBottom2;
			}
		}
	}
	cout << res;
}

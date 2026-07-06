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
#define pib pair<int,bool>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vib vector<pib>
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "bai1"

int s[10];
int M[(1 << 20) + 20];
int f[111][25];
int cost[(1 << 20) + 20][105];
int dp[(1 << 20) + 20][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	int initMask = 0;

	FOR(i, 1, 4) {
		cin >> s[i];
		s[i]--;
		initMask = TURNON(initMask, s[i]);
	}

	FOR(i, 0, k - 1) {
		string t;
		cin >> t;
		FOR(j, 0, k - 1) {
			if (t[j] == '1')
				M[MASK(i)] = TURNON(M[MASK(i)], j);
		}
	}

	FOR(mask, 1, (1 << k) - 1) {
		if (__builtin_popcount(mask) >= 4)continue;
		FOR(j, 0, k - 1) {
			if (BIT(mask, j))continue;

			int newMask = TURNON(mask, j);

			M[newMask] |= M[mask];
		}
	}

	{
		int cnt = 1, t, a;
		FOR(i, 1, n) {
			cin >> t;
			if (t == 1) {
				cin >> a;
				f[cnt][a - 1]++;
			}
			else {
				cnt++;
			}
		}
		n = cnt;
	}

	FOR(mask, 1, (1 << k) - 1) {
		if (__builtin_popcount(mask) != 4)continue;

		FOR(i, 1, n) {
			FOR(j, 0, k - 1)
				cost[mask][i] += BIT(M[mask], j) * f[i][j];
		}
	}

	dp[initMask][1] = cost[initMask][1] + 1;

	FOR(mask, 1, (1 << k) - 1) {
		if (__builtin_popcount(mask) != 4)continue;
		FOR(x, 0, k - 1) {
			if (!BIT(mask, x))continue;

			FOR(y, 0, k - 1) {
				if (BIT(mask, y))continue;

				FOR(i, 2, n) {
					if (dp[mask][i - 1] == 0)continue;

					dp[mask][i] = dp[mask][i - 1] + cost[mask][i];

					int newMask = TURNON(TURNOFF(mask, x), y);

					dp[newMask][i] = max(dp[newMask][i], dp[mask][i - 1] + cost[newMask][i]);
				}
			}
		}
	}

	int res = 0;
	FOR(i, 1, (1 << k) - 1)res = max(res, dp[i][n]);
	cout << res - 1;
}
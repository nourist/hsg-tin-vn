#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); ++i)
#define FOD(i,r,l) for (int i = (r); i >= (l); --i)
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
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define BIT(x, i) (((x) >> (i)) & 1)
#define BIT_COUNT(x) __builtin_popcountll(x)
#define LOWEST_BIT(x) __builtin_ctzll(x)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "b2"

int a[(int)5e3 + 3];
bool dpl[(int)5e3 + 3][(int)5e3 + 3];
bool dpr[(int)5e3 + 3][(int)5e3 + 3];
int f[(int)5e3 + 3][(int)5e3 + 3];
bool ok[(int)5e3 + 3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, p;
	cin >> n >> p;
	FOR(i, 1, n)cin >> a[i];

	dpl[0][0] = 1;
	FOR(i, 1, n) {
		FOR(j, 0, p)dpl[i][j] = dpl[i - 1][j];
		FOR(j, 0, p) {
			if (j + a[i] <= p) {
				dpl[i][j + a[i]] |= dpl[i - 1][j];
			}
		}
	}
	dpr[n + 1][0] = 1;
	FOD(i, n, 1) {
		FOR(j, 0, p)dpr[i][j] = dpr[i + 1][j];
		FOR(j, 0, p) {
			if (j + a[i] <= p) {
				dpr[i][j + a[i]] |= dpr[i + 1][j];
			}
		}
	}
	FOR(i, 1, n + 1) {
		FOR(j, 0, p)f[i][j] = dpr[i][j];
		FOR(j, 1, p)f[i][j] += f[i][j - 1];
	}

	FOR(i, 1, n) {
		FOR(l, 0, p - 1) {
			if (dpl[i - 1][l]) {
				int rMax = p - l - 1;
				int rMin = p - a[i] - l - 1;
				if (f[i + 1][rMax] - (rMin < 0 ? 0 : f[i + 1][rMin]) >= 1)ok[i] = 1;
			}
		}
	}
	FOR(i, 1, n)if (ok[i])cout << i << ' ';
}

/*
i: s < p; s + a[i] >= p
p - a[i] <= l+r < p
p - a[i] - l <= r < p-l
*/

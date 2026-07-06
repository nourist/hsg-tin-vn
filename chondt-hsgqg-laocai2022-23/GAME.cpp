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
#define Name "game"

int n, k;
int a[(int)1e6 + 6];
int f[25];
ll cost[25][(1 << 20) + 20];// chi phí để đưa màu i lên trước màu trong tập mask
ll dp[(1 << 20) + 20];// chi phí nhỏ nhất để sx tập mask 

void solve() {
	memset(cost, 0, sizeof cost);
	memset(f, 0, sizeof f);

	FOR(i, 1, n) {
		f[a[i]]++;
		FOR(c, 0, k - 1) {
			if (a[i] == c)continue;

			cost[a[i]][MASK(c)] += f[c];
		}
	}

	FOR(c, 0, k - 1) {
		FOR(j, 0, k - 1) {
			FOR(mask, 1, (1 << k) - 1) {
				if (BIT(mask, j))continue;

				int newMask = TURNON(mask, j);
				cost[c][newMask] += cost[c][mask];
			}
		}
	}

	FOR(i, 1, (1 << k) - 1)dp[i] = 1e18;

	FOR(mask, 0, (1 << k) - 1) {
		FOR(j, 0, k - 1) {
			if (BIT(mask, j))continue;

			int newMask = TURNON(mask, j);

			dp[newMask] = min(dp[newMask], dp[mask] + cost[j][newMask ^ ((1 << k) - 1)]);
		}
	}

	cout << dp[(1 << k) - 1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	while (cin >> n >> k) {
		if (n == 0 && k == 0)break;
		FOR(i, 1, n)cin >> a[i];
		FOR(i, 1, n)a[i]--;
		solve();
	}
}
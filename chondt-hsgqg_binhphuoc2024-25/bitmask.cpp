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
#define Name "bitmask"

int a[(int)1e6 + 6];
int f1[(1 << 20) + 20];
int f2[(1 << 20) + 20];
ll g1[(1 << 20) + 20];
ll g2[(1 << 20) + 20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, q;
	cin >> n >> q;
	FOR(i, 1, n)cin >> a[i];

	FOR(i, 1, n)f1[a[i]]++;
	FOR(i, 1, n)f2[a[i]]++;

	FOR(j, 0, 19)FOR(mask, 0, (1 << 20) - 1) {
		if (BIT(mask, j))continue;

		int newMask = TURNON(mask, j);

		f1[mask] += f1[newMask];
		f2[newMask] += f2[mask];
	}

	FOR(mask, 0, (1 << 20) - 1)g1[mask] = 1LL * f1[mask] * (f1[mask] - 1) / 2;
	FOR(mask, 0, (1 << 20) - 1)g2[mask] = 1LL * f2[mask] * (f2[mask] - 1) / 2;
	FOR(j, 0, 19)FOR(mask, 0, (1 << 20) - 1) {
		if (BIT(mask, j))continue;

		int newMask = TURNON(mask, j);

		g1[mask] -= g1[newMask];
		g2[newMask] -= g2[mask];
	}

	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;

		if (t == 1) {
			cout << g1[x ^ y] << '\n';
		}
		else {
			cout << g2[x ^ y] << '\n';
		}
	}
}

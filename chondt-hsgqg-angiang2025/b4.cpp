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
#define Name "b4"

int f[(1 << 20) + 20];
int g[(1 << 20) + 20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int m, n;
	cin >> m >> n;
	FOR(i, 1, m) {
		string s;
		cin >> s;

		int mask = 0;
		FOR(j, 0, n - 1) {
			if (s[j] == '+')mask = TURNON(mask, j);
		}
		f[mask]++;
		g[mask]++;
	}

	FOR(j, 0, n - 1)FOR(mask, 0, (1 << n) - 1) {
		if (BIT(mask, j))continue;

		int newMask = TURNON(mask, j);
		g[newMask] += g[mask];
	}

	ll res = 0;
	FOR(i, 0, (1 << n) - 1) {
		res += 1LL * (g[i] - f[i]) * f[i];
	}
	cout << res;
}

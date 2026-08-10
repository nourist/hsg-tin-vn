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
#define Name "BSEQUENCE"

int a[(int)1e6 + 6];
ll f[(int)1e6 + 6];

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
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)f[i] = f[i - 1] + a[i];

	ll res = 0;
	vii gcdS;
	FOR(i, 1, n) {
		vii nxt;
		nxt.pb({ a[i], i });

		for (auto it : gcdS) {
			int newGcd = __gcd(a[i], it.X);
			if (newGcd == nxt.back().X) {
				nxt.back().Y = it.Y;
			}
			else {
				nxt.pb({ newGcd, it.Y });
			}
		}

		gcdS = nxt;

		FOR(j, 0, gcdS.size() - 1) {
			if (i - gcdS[j].Y + 1 >= k) {
				res = max(res, gcdS[j].X * (f[i] - f[gcdS[j].Y - 1]));
			}
		}
	}
	cout << res;
}

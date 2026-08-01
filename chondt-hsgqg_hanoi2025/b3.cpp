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
#define Name "b3"

int n;
int a[(int)1e6 + 6];
int f[(int)1e6 + 6][4];

ll getKey(int x, int y) {
	return (1ULL << 30) * x + y;
}

ll range(int l, int r, vi& vals) {
	unordered_map<ll, int>mp;
	mp[getKey(f[l - 1][vals[0]] - f[l - 1][vals[1]], f[l - 1][vals[0]] - f[l - 1][vals[2]])]++;
	ll res = 0;
	FOR(i, l, r) {
		res += mp[getKey(f[i][vals[0]] - f[i][vals[1]], f[i][vals[0]] - f[i][vals[2]])]++;
	}
	return res;
}

ll solveT(int t) {
	vi vals;
	FOR(i, 0, 3)if (i != t)vals.push_back(i);

	ll res = 0;
	int cnt = 0;
	FOR(i, 1, n) {
		if (a[i] != t) {
			cnt++;
		}
		else if (cnt != 0) {
			res += range(i - cnt, i - 1, vals);
			cnt = 0;
		}
	}
	if (cnt != 0) {
		res += range(n - cnt + 1, n, vals);
		cnt = 0;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n) {
		FOR(j, 0, 3)f[i][j] = f[i - 1][j];
		f[i][a[i]]++;
	}

	ll res = 0;
	FOR(i, 0, 3)res += solveT(i);
	cout << res;
}

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
#define Name "chut"

int x[1003];
int y[1003];
int f[1003][1003];
int row[1003];
int col[1003];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> x[i] >> y[i];

	FOR(i, 1, n) {
		f[x[i]][y[i]]++;
		row[x[i]]++;
		col[y[i]]++;
	}

	ll res = 0;
	FOR(i, 1, n)FOR(j, i + 1, n) {
		if (x[i] == x[j] && y[i] != y[j] && abs(y[i] - y[j]) % 2 == 0) {
			int mid = (y[i] + y[j]) / 2;

			res += f[x[i]][mid] * (col[mid] - f[x[i]][mid]);
		}
		if (y[i] == y[j] && x[i] != x[j] && abs(x[i] - x[j]) % 2 == 0) {
			int mid = (x[i] + x[j]) / 2;

			res += f[mid][y[i]] * (row[mid] - f[mid][y[i]]);
		}
	}
	cout << res;
}

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
#define Name "cuahang"

int f[(int)1e5 + 5][3];
int mn[(int)1e5 + 5][3];
int mx[(int)1e5 + 5][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	FOR(i, 1, 1e5)FOR(j, 0, 2)mn[i][j] = 1e9;

	string s;
	cin >> s;

	int n = s.size();
	s = "_" + s;

	FOD(i, n, 1) {
		FOR(j, 0, 2)f[i][j] = f[i + 1][j];
		if (s[i] == 'H')f[i][0]++;
		else if (s[i] == 'S')f[i][1]++;
		else f[i][2]++;
	}

	FOD(i, n, 1) {
		FOR(j, 0, 2) {
			mn[f[i][j]][j] = min(mn[f[i][j]][j], i);
			mx[f[i][j]][j] = max(mx[f[i][j]][j], i);
		}
	}

	ll res = 0;
	FOD(i, n, 1) {
		vii range[3];

		FOR(j, 0, 2)
			for (int c = 1; c <= 1e5 - f[i + 1][j]; c *= 2) {
				int cnt = f[i + 1][j] + c;

				int l = mn[cnt][j];
				int r = mx[cnt][j];

				if (l == 1e9)continue;

				range[j].push_back({ l, r });
			}

		for (auto r1 : range[0])for (auto r2 : range[1])for (auto r3 : range[2]) {
			int l = max({ r1.X, r2.X, r3.X });
			int r = min({ r1.Y, r2.Y, r3.Y });

			res += max(0, (r - l + 1));
		}
	}
	cout << res;
}
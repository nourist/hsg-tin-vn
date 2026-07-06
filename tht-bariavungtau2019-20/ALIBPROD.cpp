#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define FOR(a,b,c) for (int a = b; a <= c; a++)
#define FOD(a,b,c) for (int a = b; a >= c; a--)

int n, m, a[(int)101], b[(int)1e4 + 4];
bool f[(int)1e4 + 4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("ALIBPROD.inp", "r")) {
		freopen("ALIBPROD.inp", "r", stdin);
		freopen("ALIBPROD.out", "w", stdout);
	}

	cin >> n >> m;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, m) cin >> b[i];

	f[0] = 1;
	FOR(i, 1, n) FOD(j, 1e4 + 4, a[i]) f[j] = f[j] || f[j - a[i]];
	int res = 0;
	FOR(i, 1, m) res+=f[b[i]];
	cout << res;
}
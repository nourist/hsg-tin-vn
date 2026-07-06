#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)1e5 + 5], b[(int)1e5 + 5];
int pos[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("Chocolate.inp", "r")) {
		freopen("Chocolate.inp", "r", stdin);
		freopen("Chocolate.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)cin >> b[i];

	FOR(i, 1, n)pos[b[i]] = i;
	FOR(i, 1, n)a[i] = pos[a[i]];

	int res = 1;
	FOR(i, 2, n)if (a[i] - a[i - 1] != 1)res++;
	cout << res;
}

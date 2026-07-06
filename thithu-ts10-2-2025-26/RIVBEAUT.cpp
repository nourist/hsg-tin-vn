#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int a[(int)1e5 + 5], evenodd[(int)1e5 + 5], l[(int)1e5 + 5], r[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("RIVBEAUT.inp", "r")) {
		freopen("RIVBEAUT.inp", "r", stdin);
		freopen("RIVBEAUT.out", "w", stdout);
	}

	int n, q,u,v;
	cin >> n >> q;

	FOR(i, 1, n)cin >> a[i];
	evenodd[1] = 1;
	FOR(i, 2, n) {
		if (a[i] % 2 != a[i - 1] % 2)evenodd[i] = evenodd[i - 1] + 1;
		else evenodd[i] = 1;
	}
	l[n] = 1;
	FOD(i, n - 1, 1) {
		if (a[i] >= a[i + 1]) l[i] = l[i + 1] + 1;
		else l[i] = 1;
	}
	r[1] = 1;
	FOR(i, 2, n) {
		if (a[i] >= a[i - 1])r[i] = r[i - 1] + 1;
		else r[i] = 1;
	}

	while (q--) {
		cin >> u >> v;
		if (evenodd[v] >= v - u + 1 && l[u] + r[v] >= v - u + 1)cout << "YES\n";
		else cout << "NO\n";
	}
}

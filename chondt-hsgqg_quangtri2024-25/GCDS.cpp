#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define endl '\n'

int a[(int)5e5 + 5];
ll f[(int)5e5 + 5];
vi divs[(int)5e5 + 5];

const ll mod = 1e9 + 7;
ll res = 0;

void process(int n, bool delta) {
	for (int i : divs[n]) {
		int j = n / i;
		if (delta) {
			res = (res + 1LL * j * f[i]) % mod;
			f[i] += j;
		}
		else {
			f[i] -= j;
			res = (res - 1LL * j * f[i] % mod + mod) % mod;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("GCDS.inp", "r")) {
		freopen("GCDS.inp", "r", stdin);
		freopen("GCDS.out", "w", stdout);
	}

	for (int i = 1; i * i <= 5e5; i++) {
		divs[i * i].pb(i);
		for (int j = i * (i + 1); j <= 5e5; j += i) {
			divs[j].pb(i);
			divs[j].pb(j / i);
		}
	}

	int n, q;
	cin >> n >> q;

	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n) {
		process(a[i], 1);
	}

	cout << res << endl;

	while (q--) {
		int x, y;
		cin >> x >> y;
		process(a[x], 0);
		a[x] = y;
		process(a[x], 1);
		cout << res << endl;
	}
}

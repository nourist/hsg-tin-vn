#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

const ll mod = 1e9 + 7;
int n, s, k;

namespace sub1 {
	ll mx[(int)1e6 + 6];
	ll f[55][(int)1e6 + 6];

	void solve() {
		FOR(i, 1, 1e6)mx[i] = min(n / i, s - i);

		FOR(i, 1, s)f[1][i] = 1;
		FOR(t, 2, k) {
			FOR(i, 1, s) {
				f[t][mx[i]] += f[t - 1][i];
				f[t][mx[i]] %= mod;
			}
			FOD(i, s, 1) {
				f[t][i] += f[t][i + 1];
				f[t][i] %= mod;
			}
		}

		cout << accumulate(f[k] + 1, f[k] + s + 1, 0) % mod << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("DAYSO.inp", "r")) {
		freopen("DAYSO.inp", "r", stdin);
		freopen("DAYSO.out", "w", stdout);
	}

	cin >> n >> s >> k;

	sub1::solve();
}

/*
f[i]

a*b<=n
a+b<=s

b <= n/a
b <= s-a

1 <= b <= min(n/a, s-a)

n/a <= s-a

n <= a(s-a)

*/
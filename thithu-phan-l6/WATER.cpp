#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

struct Water {
	ll z, t, id;
}a[(int)1e3 + 3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("WATER.inp", "r")) {
		freopen("WATER.inp", "r", stdin);
		freopen("WATER.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i].t >> a[i].z;
		a[i].id = i;
	}

	sort(a + 1, a + n + 1, [&](Water x, Water y) {
		return x.z > y.z;
		});

	ll sum = 0;

	FOR(i, 1, n) sum += a[i].t;

	FOR(i, 1, n) {
		a[i].t = min(sum, a[i].z);
		sum -= a[i].t;
	}

	sort(a + 1, a + n + 1, [&](Water x, Water y) {
		return x.id < y.id;
		});

	int res = 0;
	FOR(i, 1, n)if (a[i].t == 0)res++;

	cout << res << endl;

	FOR(i, 1, n)cout << a[i].t << ' ';
}

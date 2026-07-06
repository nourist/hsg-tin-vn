#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define K first 
#define T second 
#define pii pair<int,int>

pii a[(int)5e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("MAXPOINT.inp", "r")) {
		freopen("MAXPOINT.inp", "r", stdin);
		freopen("MAXPOINT.out", "w", stdout);
	}

	int m, n;
	cin >> m >> n;

	FOR(i, 1, n) {
		cin >> a[i].K >> a[i].T;
	}

	sort(a + 1, a + n + 1, greater<pii>());

	ll res = 0;
	ll total = m * 6;
	FOR(i, 1, n) {
		ll cnt = min({ 1LL * a[i].T, 1LL * m, total });
		res += cnt * a[i].K;
		total -= cnt;
	}
	cout << res;
}

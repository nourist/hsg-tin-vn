#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FOD(i,b,a) for(int i = b; i >= a; i--)
#define A first
#define B second
#define pii pair<int,int>
#define Name ""

int n, m;
pii a[(int)1e3 + 3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".ans", "w", stdout);
	}

	cin >> n >> m;
	FOR(i, 1, n)cin >> a[i].A;
	FOR(i, 1, n)cin >> a[i].B;

	sort(a + 1, a + n + 1, [&](pii x, pii y) {
		return x.B - x.A < y.B - y.A;
		});

	FOR(i, 1, n) {
		if (m >= a[i].B - a[i].A) {
			m += a[i].A;
		}
	}

	cout << m;
}

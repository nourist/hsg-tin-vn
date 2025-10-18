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

struct Data {
	int A, B, idx;
};

Data a[(int)1e4 + 4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".ans", "w", stdout);
	}

	int n;
	cin >> n;

	FOR(i, 1, n)cin >> a[i].A;
	FOR(i, 1, n)cin >> a[i].B;
	FOR(i, 1, n)a[i].idx = i;

	sort(a + 1, a + n + 1, [&](Data x, Data y) {
		return (double)x.A / x.B < (double)y.A / y.B;
		});

	ll res = 0, day = 0;
	FOD(i, n, 1) {
		day += a[i].B;
		res += day * a[i].A;
	}
	cout << res << endl;
	FOD(i, n, 1)cout << a[i].idx << ' ';
}

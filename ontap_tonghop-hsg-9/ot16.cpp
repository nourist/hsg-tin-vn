#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FOD(i,b,a) for(int i = b; i >= a; i--)
#define pii pair<int,int>
#define A first
#define B second
#define Name "barray"

ll a[(int)1e6 + 6], f[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, q;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	cin >> q;
	FOR(i, 1, q) {
		int l, r, x;
		cin >> l >> r >> x;
		f[l] += x;
		f[r + 1] -= x;
	}
	FOR(i, 1, 1e6)f[i] += f[i - 1];
	FOR(i, 1, n)cout << f[i] + a[i] << ' ';
}

/*
*/

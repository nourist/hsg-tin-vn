#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll f[(int)2e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n,x,d,k;
	cin >> n;

	int End = 0;
	FOR(i, 1, n) {
		cin >> x >> d >> k;
		f[x*2] += k;
		f[(x + d)*2 + 1] -= k;
		End = max(End, (x + d)*2);
	}
	FOR(i, 1, 2e5)f[i] += f[i - 1];
	FOR(i, 1, End)if (f[i] != f[i - 1])cout << f[i] << ' ';
}
